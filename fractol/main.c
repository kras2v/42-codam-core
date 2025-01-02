/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:32:58 by kvalerii          #+#    #+#             */
/*   Updated: 2025/01/03 00:05:27 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <time.h>

void newton(t_img_data *img_data)
{
	t_pixels pixels;
	pixels.py = 0;
	int color;
	color = 0;
	while (pixels.py < HEIGHT) 
	{
		img_data->fractol.c.imag = convert_pixel_to_coordinate(pixels.py, img_data, 'y');
		pixels.px = 0;
		while (pixels.px < WIDTH)
		{
			img_data->fractol.c.real = convert_pixel_to_coordinate(pixels.px, img_data, 'x');
			color = calc_n(img_data->fractol);
			my_put_pixel(img_data, pixels.px, pixels.py, color);
			pixels.px++;
		}
		pixels.py++;
	}
}

void mandelbrot(t_img_data *img_data)
{
	t_pixels pixels;
	int color;

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
		z.imag = -convert_pixel_to_coordinate(pixels.py, img_data, 'y');
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

void proceed_argv_mandelbrot(t_my_display *my_display, int max_iterations)
{
	(*my_display) = create_my_display(max_iterations);
	(*my_display).img_data.fractol.name = 'M';
	mandelbrot(&((*my_display).img_data));
}

void proceed_argv_newton(t_my_display *my_display, int max_iterations)
{
	(*my_display) = create_my_display(max_iterations);
	(*my_display).img_data.fractol.name = 'N';
	(*my_display).img_data.fractol.scale.min_scale_X = -2.5;
	(*my_display).img_data.fractol.scale.max_scale_X = 2.5;
	(*my_display).img_data.fractol.scale.min_scale_Y = -2.5;
	(*my_display).img_data.fractol.scale.max_scale_Y = 2.5;
	newton(&((*my_display).img_data));
}

void proceed_argv_julia(t_complex c, t_my_display *my_display, int max_iterations)
{
	double R;

	R = 1.8;
	(*my_display) = create_my_display(max_iterations);
	(*my_display).img_data.fractol.name = 'J';
	(*my_display).img_data.fractol.c.real = c.real;
	(*my_display).img_data.fractol.c.imag = c.imag;
	(*my_display).img_data.fractol.scale.min_scale_X = -R;
	(*my_display).img_data.fractol.scale.min_scale_Y = -R;
	(*my_display).img_data.fractol.scale.max_scale_X = R;
	(*my_display).img_data.fractol.scale.max_scale_Y = R;
	julia(&((*my_display).img_data));
}

int main(int argc, char **argv)
{
	t_my_display my_display;
	int max_iterations;
	t_complex c;

	c.real = 0;
	c.imag = 0;
	if(argc != 2 && argc != 4)
	{
		free_and_exit(NULL, 1, "Wrong amount of arguments");
	}
	max_iterations = 100;
	if ((argc == 2) && (ft_strcmp(argv[1], "Mandelbrot") == 0))
		proceed_argv_mandelbrot(&my_display, max_iterations);
	if ((argc == 2) && (ft_strcmp(argv[1], "Newton") == 0))
		proceed_argv_newton(&my_display, max_iterations);
	else if (ft_strcmp(argv[1], "Julia") == 0)
	{
		if (argc == 2)
		{
			c.real = -0.4;
			c.imag = 0.6;
		}
		else if (argc == 4)
		{
			c.real = ft_atof(argv[2], &my_display);
			c.imag = ft_atof(argv[3], &my_display);
		}
		proceed_argv_julia(c, &my_display, max_iterations);
	}
	else
		free_and_exit(NULL, 1, "Wrong amount of arguments");
	printf("DONE\n");
	mlx_put_image_to_window(my_display.mlx, my_display.win, my_display.img_data.img_ptr, 0, 0);
	identify_event_handlers(&my_display);
	mlx_loop(my_display.mlx);
	return (0);
}

