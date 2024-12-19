/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:32:58 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/19 19:03:06 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <time.h>



int main(void)
{
	t_my_display my_display;

	my_display.mlx = mlx_init();
	my_display.win = mlx_new_window(my_display.mlx, WIDTH, HEIGHT, "Fractol");
	my_display.img_data.img_ptr = mlx_new_image(my_display.mlx, WIDTH, HEIGHT);
	my_display.img_data.data_addr = mlx_get_data_addr(my_display.img_data.img_ptr, 
													&my_display.img_data.bites_per_pixel, 
													&my_display.img_data.size_line,
													&my_display.img_data.endian);
	int px = 0;
	int py = 0;
	int curr_iterations = 0;
	int max_iterations = 1000;
	int color;
	while (py < HEIGHT)
	{
		px = 0;
		double y = scale_pixel_to_coord(py, HEIGHT, min_scale_Y, max_scale_Y);
		while (px < WIDTH)
		{
			double x = scale_pixel_to_coord(px, WIDTH, min_scale_X, max_scale_X);
			t_compex c = {x, y};
			curr_iterations = calc(c, max_iterations);
			color = 0xFF0000;
			if (curr_iterations == max_iterations)
				my_put_pixel(&my_display.img_data, px, py, 0x000000);
			else if (curr_iterations > max_iterations * 0.5)
				my_put_pixel(&my_display.img_data, px, py, 0xAF0000);
			else if (curr_iterations < max_iterations * 0.1)
				my_put_pixel(&my_display.img_data, px, py, 0x0000F0);
			else
				my_put_pixel(&my_display.img_data, px, py, 0xFFFFFF);
			px++;
		}
		py++;
	}
	mlx_put_image_to_window(my_display.mlx, my_display.win, my_display.img_data.img_ptr, 0, 0);
	mlx_loop(my_display.mlx);
	return (0);
}
