/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:32:58 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/23 17:08:54 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <time.h>

void mandelbrot(t_img_data *img_data)
{
	t_pixels pixels;
	t_complex coordinates;
	int color;

	pixels.py = 0;
	while (pixels.py < img_data->size.max_Y)
	{
		pixels.px = 0;
		coordinates.imag = convert_pixel_to_coordinate(pixels.py, img_data, 'y');
		while (pixels.px < img_data->size.max_X)
		{
			coordinates.real = convert_pixel_to_coordinate(pixels.px, img_data, 'x');
			t_complex c = {coordinates.real, coordinates.imag};
			color = calc_m(c,  img_data->max_iterations);
			my_put_pixel(img_data, pixels.px, pixels.py, color);
			pixels.px++;
		}
		pixels.py++;
	}
}

void julia(t_img_data *img_data)
{
	t_pixels pixels;
	t_complex coordinates;
	int color;

	pixels.py = 0;
	while (pixels.py < img_data->size.max_Y)
	{
		pixels.px = 0;
		coordinates.imag = convert_pixel_to_coordinate(pixels.py, img_data, 'y');
		while (pixels.px < img_data->size.max_X)
		{
			coordinates.real = convert_pixel_to_coordinate(pixels.px, img_data, 'x');
			t_complex z = {-coordinates.real, coordinates.imag};
			t_complex c = {-0.4, 0.6};
			color = calc_j(z, c, img_data->max_iterations);
			my_put_pixel(img_data, pixels.px, pixels.py, color);
			pixels.px++;
		}
		pixels.py++;
	}
}

int main(int argc, char **argv)
{
	t_my_display my_display;

	if (argc == 2 && (ft_strcmp(argv[1], "Mandelbrot") == 0 || ft_strcmp(argv[1], "Julia") == 0))
	{
		my_display = create_my_display(1000);
		if (ft_strcmp(argv[1], "Mandelbrot") == 0)
		{
			my_display.img_data.fractol = "Mandelbrot";
			mandelbrot(&(my_display.img_data));
		}
		else if (ft_strcmp(argv[1], "Julia") == 0)
		{
			double R = 1.7;
			my_display.img_data.fractol = "Julia";
			my_display.img_data.scale.min_scale_X = -R;
			my_display.img_data.scale.min_scale_Y = -R;
			my_display.img_data.scale.max_scale_X = R;
			my_display.img_data.scale.max_scale_Y = R;
			julia(&(my_display.img_data));
		}
		mlx_put_image_to_window(my_display.mlx, my_display.win, my_display.img_data.img_ptr, 0, 0);
		identify_event_handlers(&my_display);
		mlx_loop(my_display.mlx);
	}
	return (0);
}
