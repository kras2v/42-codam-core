/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:12:14 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/22 20:43:16 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double scale_pixel_to_coord(int pix, int size, double min, double max)
{
	return (min + (pix / (double)size) * (max - min));
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
	my_display.img_data.img_ptr = mlx_new_image(my_display.mlx, WIDTH, HEIGHT);
	if (!my_display.img_data.img_ptr)
		free_and_exit(&my_display, 1);
	my_display.img_data.data_addr = mlx_get_data_addr(my_display.img_data.img_ptr, 
													&my_display.img_data.bites_per_pixel, 
													&my_display.img_data.size_line,
													&my_display.img_data.endian);
	if (!my_display.img_data.data_addr)
		free_and_exit(&my_display, 1);
	my_display.img_data.max_iterations = max_iterations;
	my_display.img_data.size.min_X = 0;
	my_display.img_data.size.min_Y = 0;
	my_display.img_data.size.max_X = WIDTH;
	my_display.img_data.size.max_Y = HEIGHT;
	return (my_display);
}
