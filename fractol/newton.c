/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newton.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 13:57:27 by kvalerii          #+#    #+#             */
/*   Updated: 2025/01/04 18:26:34 by kvalerii         ###   ########.fr       */
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

t_complex	get_root(double real, double imag)
{
	t_complex	root;

	root.real = real;
	root.imag = imag;
	return (root);
}

//bool
int	get_closest_root_position(t_complex c)
{
	t_complex	roots[3];
	int			j;
	double		tolerance;

	roots[0] = get_root(1.0, 0.0);
	roots[1] = get_root(-0.5, sqrt(3) / 2);
	roots[2] = get_root(-0.5, -sqrt(3) / 2);
	tolerance = 0.000001;
	j = 0;
	while (j < 3)
	{
		if (fabs(c.real - roots[j].real) <= tolerance && fabs(c.imag - roots[j].imag) <= tolerance)
			return (j + 1);
		j++;
	}
	return (-1);
}

int	calc_n(t_fractol newton, t_color change)
{
	int	i;
	int	closest_root;
	
	i = 0;
	closest_root = 0;
	while (i < newton.max_iterations)
	{
		t_complex deriv = derivative(newton.c);
		if (fabs(deriv.real) < 0e-12 || fabs(deriv.imag) < 0e-12)
			break;
		t_complex division_px_der_px = division(func(newton.c), deriv);
		newton.c = subtraction(newton.c, division_px_der_px);
		closest_root = get_closest_root_position(newton.c);
		if (get_closest_root_position(newton.c) >= 0)
			return (newton_coloring(closest_root, change));
		i++;
	}
	return (newton_coloring(closest_root, change));
}
