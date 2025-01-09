/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_display_img.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:03:28 by valeriia          #+#    #+#             */
/*   Updated: 2025/01/09 18:59:18 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include <stdlib.h>

void	my_put_pixel(t_img_data *img, int x, int y, int color)
{
	int	offset;

	offset = y * img->size_line + x * (img->bites_per_pixel / 8);
	*((unsigned int *)(offset + img->data_addr)) = color;
}

void	init_img_size(t_img_size *img_size, t_pixels min, t_pixels max)
{
	img_size->min_px = min.px;
	img_size->max_px = max.px;
	img_size->min_py = min.py;
	img_size->max_py = max.py;
}

void	create_img_data(t_my_display *my_display)
{
	t_pixels	min_pixel;
	t_pixels	max_pixel;

	my_display->img_data.img_ptr = mlx_new_image(my_display->mlx,
			WIDTH, HEIGHT);
	if (!my_display->img_data.img_ptr)
		free_and_exit(my_display, 1,
			"Error occurate while allocating memory for image");
	my_display->img_data.data_addr = mlx_get_data_addr(
			my_display->img_data.img_ptr, &my_display->img_data.bites_per_pixel,
			&my_display->img_data.size_line, &my_display->img_data.endian);
	if (!my_display->img_data.data_addr)
		free_and_exit(my_display, 1,
			"Error occurate getting address of first pixel");
	min_pixel.px = 0;
	min_pixel.py = 0;
	max_pixel.px = WIDTH;
	max_pixel.py = HEIGHT;
	init_img_size(&(my_display->img_data.size), min_pixel, max_pixel);
}

t_my_display	create_my_display(void)
{
	t_my_display	my_display;

	my_display.img_data.img_ptr = NULL;
	my_display.mlx = NULL;
	my_display.win = NULL;
	my_display.mlx = mlx_init();
	if (!my_display.mlx)
		free_and_exit(&my_display, 1,
			"Error occurate while allocating memory for display");
	my_display.win = mlx_new_window(my_display.mlx, WIDTH, HEIGHT, "Fractol");
	if (!my_display.win)
		free_and_exit(&my_display, 1,
			"Error occurate while allocating memory for window");
	create_img_data(&my_display);
	return (my_display);
}
