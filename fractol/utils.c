/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:12:14 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/25 11:33:54 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double get_scale_factor(int min, int max, double min_scale, double max_scale)
{
	return ((max_scale - min_scale) / (double)(max - min));
}

double convert_pixel_to_coordinate(int pix, t_img_data *img_data, char direction)
{
	t_complex scale;
	t_complex scale_factor;

	if (direction == 'x')
	{
		scale.real = get_scale_factor(img_data->size.min_px, img_data->size.max_px, img_data->fractol.scale.min_scale_X, img_data->fractol.scale.max_scale_X);
		scale_factor.real = (double)(img_data->fractol.scale.min_scale_X - img_data->size.min_px * scale.real);
		return (pix * scale.real + scale_factor.real);
	}
	else if (direction == 'y')
	{
		scale.imag = get_scale_factor(img_data->size.min_py, img_data->size.max_py, img_data->fractol.scale.min_scale_Y, img_data->fractol.scale.max_scale_Y);
		scale_factor.imag = (double)(img_data->fractol.scale.min_scale_Y - img_data->size.min_py * scale.imag);
		return (pix * scale.imag + scale_factor.imag);
	}
	return (0.0);
}

void	my_put_pixel(t_img_data *img, int x, int y, int color)
{
	int	offset;

	offset = y * img->size_line + x * (img->bites_per_pixel / 8);
	*((unsigned int*)(offset + img->data_addr)) = color;
}

void free_and_exit(t_my_display *my_display, int exit_code)
{
	if (my_display->mlx != NULL)
	{
		if (my_display->img_data.img_ptr != NULL)
			mlx_destroy_image(my_display->mlx, my_display->img_data.img_ptr);
		if (my_display->win != NULL)
			mlx_destroy_window(my_display->mlx, my_display->win);
		mlx_destroy_display(my_display->mlx);
		free(my_display->mlx);
	}
	exit(exit_code);
}

void init_scale(t_scale *scale, double min_X, double max_X, double min_Y, double max_Y) {
	scale->min_scale_X = min_X;
	scale->max_scale_X = max_X;
	scale->min_scale_Y = min_Y;
	scale->max_scale_Y = max_Y;
}

void create_img_data(t_my_display *my_display, unsigned int max_iterations)
{
	my_display->img_data.img_ptr = mlx_new_image(my_display->mlx, WIDTH, HEIGHT);
	if (!my_display->img_data.img_ptr)
		free_and_exit(my_display, 1);
	my_display->img_data.data_addr = mlx_get_data_addr(my_display->img_data.img_ptr, 
													&my_display->img_data.bites_per_pixel, 
													&my_display->img_data.size_line,
													&my_display->img_data.endian);
	if (!my_display->img_data.data_addr)
		free_and_exit(my_display, 1);
	my_display->img_data.fractol.max_iterations = max_iterations;
	my_display->img_data.fractol.scale.min_scale_X = -2;
	my_display->img_data.fractol.scale.max_scale_X = 0.5;
	my_display->img_data.fractol.scale.min_scale_Y = -1.2;
	my_display->img_data.fractol.scale.max_scale_Y = 1.2;
	my_display->img_data.fractol.c.imag = 0.0;
	my_display->img_data.fractol.c.real = 0.0;
	my_display->img_data.size.min_px = 0;
	my_display->img_data.size.min_py = 0;
	my_display->img_data.size.max_px = WIDTH;
	my_display->img_data.size.max_py = HEIGHT;
}

t_my_display create_my_display(unsigned int max_iterations)
{
	t_my_display my_display;

	my_display.img_data.img_ptr = NULL;
	my_display.mlx = NULL;
	my_display.win = NULL;
	my_display.mlx = mlx_init();
	if (!my_display.mlx)
		free_and_exit(&my_display, 1);
	my_display.win = mlx_new_window(my_display.mlx, WIDTH, HEIGHT, "Fractol");
	if (!my_display.win)
		free_and_exit(&my_display, 1);
	create_img_data(&my_display, max_iterations);
	return (my_display);
}
