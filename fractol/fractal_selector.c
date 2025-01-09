/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_selector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:30:52 by valeriia          #+#    #+#             */
/*   Updated: 2025/01/09 22:52:04 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	initialize_fractal_display(t_my_display *my_display,
						int max_iterations, t_scale scale, char name)
{
	(*my_display) = create_my_display();
	my_display->img_data.fractol.name = name;
	my_display->img_data.fractol.color_type = 'S';
	my_display->img_data.fractol.max_iterations = max_iterations;
	my_display->img_data.fractol.scale = scale;
}

static t_scale	get_scale(double min_real, double max_real,
							double min_imag, double max_imag)
{
	t_scale	scale;

	scale.min_real = min_real;
	scale.max_real = max_real;
	scale.min_imag = min_imag;
	scale.max_imag = max_imag;
	return (scale);
}

void	initialize_mandelbrot(t_my_display *my_display, int max_iterations)
{
	t_scale	scale;

	scale = create_scale(1.2, -1.2, 0.5, -2);
	initialize_fractal_display(my_display, max_iterations, scale, 'M');
	render_mandelbrot(&(my_display->img_data));
}

void	initialize_newton(t_my_display *my_display, int max_iterations)
{
	double	size;
	t_scale	scale;

	size = 2.5;
	scale = create_scale(size, -size, size, -size);
	initialize_fractal_display(my_display, max_iterations, scale, 'N');
	render_newton(&(my_display->img_data), 1);
}

void	initialize_julia(t_complex c,
						t_my_display *my_display, int max_iterations)
{
	double	size;
	t_scale	scale;

	size = 1.8;
	scale = get_scale(size, -size, size, -size);
	initialize_fractal_display(my_display, max_iterations, scale, 'J');
	my_display->img_data.fractol.c.real = c.real;
	my_display->img_data.fractol.c.imag = c.imag;
	render_julia(&(my_display->img_data));
}
