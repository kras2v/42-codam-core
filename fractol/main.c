/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:32:58 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/26 21:22:33 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <time.h>

void mandelbrot(t_img_data *img_data)
{
	t_pixels pixels;
	int color;
	clock_t start_time, end_time; // Declare variables for timing
	start_time = clock();

	pixels.py = 0;
	while (pixels.py < img_data->size.max_py)
	{
		pixels.px = 0;
		img_data->fractol.c.imag = convert_pixel_to_coordinate(pixels.py, img_data, 'y');
		while (pixels.px < img_data->size.max_px)
		{
			img_data->fractol.c.real = convert_pixel_to_coordinate(pixels.px, img_data, 'x');
			color = calc_m(&(img_data->fractol));
			my_put_pixel(img_data, pixels.px, pixels.py, color);
			pixels.px++;
		}
		pixels.py++;
	}
	end_time = clock();

    // Calculate elapsed time in milliseconds
    double elapsed_time = (double)(end_time - start_time) * 1000.0 / CLOCKS_PER_SEC;

    // Print or display the elapsed time
    printf("Fractal computation took %.2f milliseconds.\n", elapsed_time);
}

void julia(t_img_data *img_data)
{
	t_pixels pixels;
	t_complex z;
	int color;

	pixels.py = 0;
	while (pixels.py < img_data->size.max_py)
	{
		pixels.px = 0;
		z.imag = convert_pixel_to_coordinate(pixels.py, img_data, 'y');
		while (pixels.px < img_data->size.max_px)
		{
			z.real = convert_pixel_to_coordinate(pixels.px, img_data, 'x');
			color = calc_j(z,  &(img_data->fractol));
			my_put_pixel(img_data, pixels.px, pixels.py, color);
			pixels.px++;
		}
		pixels.py++;
	}
}

int main(int argc, char **argv)
{
	t_my_display my_display;
	double R;

	if (argc == 2 && (ft_strcmp(argv[1], "Mandelbrot") == 0))
	{
		my_display = create_my_display(100);
		if (ft_strcmp(argv[1], "Mandelbrot") == 0)
		{
			my_display.img_data.fractol.name = 'M';
			mandelbrot(&(my_display.img_data));
		}
	}
	else if ((argc == 2) && ft_strcmp(argv[1], "Julia") == 0)
	{
		my_display = create_my_display(100);
		R = 1.5;
		my_display.img_data.fractol.name = 'J';
		my_display.img_data.fractol.c.real = -0.4;
		my_display.img_data.fractol.c.imag = 0.6;
		my_display.img_data.fractol.scale.min_scale_X = -R;
		my_display.img_data.fractol.scale.min_scale_Y = -R;
		my_display.img_data.fractol.scale.max_scale_X = R;
		my_display.img_data.fractol.scale.max_scale_Y = R;
		julia(&(my_display.img_data));
		mlx_put_image_to_window(my_display.mlx, my_display.win, my_display.img_data.img_ptr, 0, 0);
		identify_event_handlers(&my_display);
		mlx_loop(my_display.mlx);
	}
	return (0);
}
