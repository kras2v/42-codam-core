/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_selector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:30:52 by valeriia          #+#    #+#             */
/*   Updated: 2025/01/04 21:55:38 by valeriia         ###   ########.fr       */
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

	scale = get_scale(-2, 0.5, -1.2, 1.2);
	initialize_fractal_display(my_display, max_iterations, scale, 'M');
	mandelbrot(&(my_display->img_data));
}

void	initialize_newton(t_my_display *my_display, int max_iterations)
{
	t_scale	scale;

	scale = get_scale(-2.5, 2.5, -2.5, 2.5);
	initialize_fractal_display(my_display, max_iterations, scale, 'N');
	newton(&(my_display->img_data));
}

void	initialize_julia(t_complex c,
						t_my_display *my_display, int max_iterations)
{
	double	r;
	t_scale	scale;

	r = 1.8;
	scale = get_scale(-r, r, -r, r);
	initialize_fractal_display(my_display, max_iterations, scale, 'J');
	my_display->img_data.fractol.c.real = c.real;
	my_display->img_data.fractol.c.imag = c.imag;
	julia(&(my_display->img_data));
}
