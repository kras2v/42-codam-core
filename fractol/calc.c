/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:37:06 by kvalerii          #+#    #+#             */
/*   Updated: 2025/01/04 15:12:03 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calc_m(t_fractol *mandelbrot)
{
	t_complex Z = {0.0, 0.0};
	t_complex Ztemp = {0.0, 0.0};

	int i = 0;
	while (i < mandelbrot->max_iterations)
	{
		Ztemp.imag = 2 * Ztemp.imag * Ztemp.real + mandelbrot->c.imag;
		Ztemp.real = Z.real - Z.imag + mandelbrot->c.real;
		Z.real = Ztemp.real * Ztemp.real;
		Z.imag = Ztemp.imag * Ztemp.imag;
		if ((Z.real + Z.imag) >= 4.0)
			break;
		i++;
	}
	if (i == mandelbrot->max_iterations)
		return create_rgb(0, 0, 0);
	if (mandelbrot->color_type == 'S')
		return standart_coloring(i, mandelbrot->max_iterations);
	return rainbow_coloring(i, Z, mandelbrot->name);
}

int	calc_j(t_complex Z, t_fractol *julia)
{
	t_complex Ztemp = {0, 0};

	int i = 0;
	double z_real_2 = Z.real * Z.real;
	double z_imag_2 = Z.imag * Z.imag;
	while (i < julia->max_iterations && (z_real_2 + z_imag_2) < 16)
	{
		z_real_2 = Z.real * Z.real;
		z_imag_2 = Z.imag * Z.imag;
		Z.imag = 2 * Z.imag * Z.real + julia->c.imag;
		Ztemp.real = z_real_2 - z_imag_2;
		Z.real = Ztemp.real + julia->c.real;
		i++;
	}
	if (i == julia->max_iterations)
		return create_rgb(0, 0, 0);
	if (julia->color_type == 'S')
		return standart_coloring(i, julia->max_iterations);
	return rainbow_coloring(i, Z, julia->name);
}

