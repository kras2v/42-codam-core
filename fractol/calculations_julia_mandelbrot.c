/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_julia_mandelbrot.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:37:06 by kvalerii          #+#    #+#             */
/*   Updated: 2025/01/10 00:20:36 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	calculate_mandelbrot(t_fractol *mandelbrot)
{
	t_complex	z;
	t_complex	z_temp;
	int			i;

	i = 0;
	z.real = 0;
	z.imag = 0;
	z_temp.real = 0;
	z_temp.imag = 0;
	while (i < mandelbrot->max_iterations)
	{
		z_temp.imag = 2 * z_temp.imag * z_temp.real + mandelbrot->c.imag;
		z_temp.real = z.real - z.imag + mandelbrot->c.real;
		z.real = z_temp.real * z_temp.real;
		z.imag = z_temp.imag * z_temp.imag;
		if ((z.real + z.imag) >= 16.0)
			break ;
		i++;
	}
	if (i == mandelbrot->max_iterations)
		return (create_rgb(0, 0, 0));
	if (mandelbrot->color_type == 'S')
		return (standart_coloring(i, mandelbrot->max_iterations));
	return (rainbow_coloring(i, z, mandelbrot->name));
}

int	calculate_julia(t_complex Z, t_fractol *julia)
{
	t_complex	z_temp;
	t_complex	z_2;
	int			i;

	i = 0;
	while (i < julia->max_iterations)
	{
		z_2.real = Z.real * Z.real;
		z_2.imag = Z.imag * Z.imag;
		Z.imag = 2 * Z.imag * Z.real + julia->c.imag;
		z_temp.real = z_2.real - z_2.imag;
		Z.real = z_temp.real + julia->c.real;
		if ((z_2.real + z_2.imag) >= 16.0)
			break ;
		i++;
	}
	if (i == julia->max_iterations)
		return (create_rgb(0, 0, 0));
	if (julia->color_type == 'S')
		return (standart_coloring(i, julia->max_iterations));
	return (rainbow_coloring(i, Z, julia->name));
}
