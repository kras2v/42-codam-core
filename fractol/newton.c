/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:57:27 by kvalerii          #+#    #+#             */
/*   Updated: 2025/01/03 22:47:47 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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

int calc_n(t_fractol newton)
{
	int i = 0;
	int j = 0;
	double tolerance = 0.0001;
	t_complex roots[3] =
	{
		{ 1.0, 0.0},
		{-0.5, sin(2* M_PI / 3)},
		{-0.5, -sin(2* M_PI / 3)},
	};
	int root_length = 3;
	t_color colors[3] = 
	{
		{255, 0, 0},
		{0, 255, 0},
		{0, 0, 255},
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
