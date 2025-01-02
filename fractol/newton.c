/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:57:27 by kvalerii          #+#    #+#             */
/*   Updated: 2025/01/03 00:02:58 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//a^3 + 3a^2b + 3ab^2 + b^3 = (x^3 - 3xy^2) + (3x^2yi - yi^3)
t_complex c_cube(t_complex z)
{
	t_complex cubed_z;

	cubed_z.real = pow(z.real, 3) - 3.0 * z.real * pow(z.imag, 2);
	cubed_z.imag = 3.0 * pow(z.real, 2) * z.imag - pow(z.imag, 3);
	return (cubed_z);
}

//a^2 + 2ab + b^2 = x^2 - y^2 + 2xyi
t_complex c_square(t_complex z)
{
	t_complex squred_z;

	squred_z.real = pow(z.real, 2) - pow(z.imag, 2);
	squred_z.imag = 2.0 * z.imag * z.real;
	return (squred_z);
}

//z^3 - 1
t_complex func(t_complex z)
{
	t_complex z_func;

	z_func = c_cube(z);
	z_func.real = z_func.real - 1.0;
	return (z_func);
}

//3*z^2 = 3 * (x^2 - y^2 + 2xyi)
t_complex derivative(t_complex z)
{
	t_complex z_deriv;

	z_deriv = c_square(z);
	z_deriv.real *= 3.0;
	z_deriv.imag *= 3.0;
	return (z_deriv);
}

//(a + bi) / (c + di) = ((a + bi)(c - di)) / ((c + di)(c - di)) =
// ((ac + bd) / (c^2 + d^2)) * ((bc - ad)i/(c^2 + d^2))
t_complex division(t_complex dividend, t_complex divisor)
{
	t_complex quotient;

	quotient.real = (dividend.real * divisor.real + dividend.imag * divisor.imag) /
					(pow(divisor.real, 2) + pow(divisor.imag, 2));
	quotient.imag = (dividend.imag * divisor.real - dividend.real * divisor.imag) /
					(pow(divisor.real, 2) + pow(divisor.imag, 2));
	return (quotient);
}

//(a + bi) - (c + di) = a - c + bi - di;
t_complex subtraction(t_complex minuend, t_complex subtrahend)
{
	t_complex difference;

	difference.real = minuend.real - subtrahend.real;
	difference.imag = minuend.imag - subtrahend.imag;
	return (difference);
}

int calc_n(t_fractol newton)
{
	int i = 0;
	int j = 0;
	double tolerance = 0.0001;
	t_complex roots[3] =
	{
		{ 1.0, 0.0},
		{-0.5, sqrt(3)/2},
		{-0.5, -sqrt(3)/2},
	};
	int root_length = 3;
	t_color colors[3] = 
	{
		{255, 0, 0}, // red
		{0, 255, 0}, // green
		{0, 0, 255}, // blue
	};
	while (i <= newton.max_iterations)
	{
		t_complex deriv = derivative(newton.c);
		if (fabs(deriv.real) < 0e-12 || fabs(deriv.imag) < 0e-12)
			break;
		t_complex division_px_der_px = division(func(newton.c), deriv);
		newton.c = subtraction(newton.c, division_px_der_px);
		j = 0;
		while (j < root_length)
		{
			if (fabs(newton.c.real - roots[j].real) <= tolerance && fabs(newton.c.imag - roots[j].imag) <= tolerance)
			{
				return create_rgb(colors[j].r, colors[j].g, colors[j].b);
			}
			j++;
		}
		i++;
	}
	return 0;
}
