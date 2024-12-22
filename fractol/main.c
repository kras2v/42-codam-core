/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:32:58 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/22 20:47:09 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <time.h>

void mandelbrot(t_img_data *img_data)
{
	t_pixels pixels;
	t_coordinates coordinates;
	int color;

	pixels.py = 0;
	while (pixels.py < HEIGHT)
	{
		pixels.px = 0;
		coordinates.y = scale_pixel_to_coord(pixels.py, HEIGHT, min_scale_Y, max_scale_Y);
		while (pixels.px < WIDTH)
		{
			coordinates.x = scale_pixel_to_coord(pixels.px, WIDTH, min_scale_X, max_scale_X);
			t_complex c = {coordinates.x, coordinates.y};
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
	t_coordinates coordinates;
	int color;
	int R = 2;

	pixels.px = 0;
	pixels.py = 0;
	while (pixels.py < HEIGHT)
	{
		pixels.px = 0;
		coordinates.y = scale_pixel_to_coord(pixels.py, HEIGHT, -R, R);
		while (pixels.px < WIDTH)
		{
			coordinates.x = scale_pixel_to_coord(pixels.px, WIDTH, -R, R);
			t_complex c = {-0.8, 0.3};
			t_complex z = {-coordinates.x, -coordinates.y};
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
			mandelbrot(&(my_display.img_data));
		else if (ft_strcmp(argv[1], "Julia") == 0)
			julia(&(my_display.img_data));
		mlx_put_image_to_window(my_display.mlx, my_display.win, my_display.img_data.img_ptr, 0, 0);
		identify_event_handlers(&my_display);
		mlx_loop(my_display.mlx);
	}
	return (0);
}
