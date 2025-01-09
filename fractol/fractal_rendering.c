/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_rendering.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:14:17 by valeriia          #+#    #+#             */
/*   Updated: 2025/01/09 18:32:44 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	newton(t_img_data *img_data)
{
	static t_color	change;
	t_pixels		pixels;
	int				color;

	pixels.py = 0;
	color = 0;
	change.r += 50;
	change.g += 60;
	change.b += 70;
	while (pixels.py < HEIGHT)
	{
		img_data->fractol.c.imag = convert_pixel_to_coordinate(
				pixels.py, img_data, &(img_data->fractol), 'y');
		pixels.px = 0;
		while (pixels.px < WIDTH)
		{
			img_data->fractol.c.real = convert_pixel_to_coordinate(
					pixels.px, img_data, &(img_data->fractol), 'x');
			color = calc_n(img_data->fractol, change);
			my_put_pixel(img_data, pixels.px, pixels.py, color);
			pixels.px++;
		}
		pixels.py++;
	}
}

void	mandelbrot(t_img_data *img_data)
{
	t_pixels	pixels;
	int			color;

	pixels.py = 0;
	while (pixels.py < img_data->size.max_py)
	{
		pixels.px = 0;
		img_data->fractol.c.imag = convert_pixel_to_coordinate(
				pixels.py, img_data, &(img_data->fractol), 'y');
		while (pixels.px < img_data->size.max_px)
		{
			img_data->fractol.c.real = convert_pixel_to_coordinate(
					pixels.px, img_data, &(img_data->fractol), 'x');
			color = calc_m(&(img_data->fractol));
			my_put_pixel(img_data, pixels.px, pixels.py, color);
			pixels.px++;
		}
		pixels.py++;
	}
}

void	julia(t_img_data *img_data)
{
	t_pixels	pixels;
	t_complex	z;
	int			color;

	pixels.py = 0;
	while (pixels.py < img_data->size.max_py)
	{
		pixels.px = 0;
		z.imag = convert_pixel_to_coordinate(
				pixels.py, img_data, &(img_data->fractol), 'y');
		while (pixels.px < img_data->size.max_px)
		{
			z.real = convert_pixel_to_coordinate(
					pixels.px, img_data, &(img_data->fractol), 'x');
			color = calc_j(z, &(img_data->fractol));
			my_put_pixel(img_data, pixels.px, pixels.py, color);
			pixels.px++;
		}
		pixels.py++;
	}
}
