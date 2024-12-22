/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:32:58 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/22 19:22:45 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <time.h>

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

int close_on_key(int keysym, t_my_display *my_display)
{
	if (keysym == XK_Escape)
	{
		free_and_exit(my_display, 0);
		return (0);
	}
	return (1);
}

int close_on_event(t_my_display *my_display)
{
	free_and_exit(my_display, 0);
	return (0);
}

t_my_display create_my_display()
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
	return (my_display);
}

int main(void)
{
	t_my_display my_display;

	my_display = create_my_display();
	int px = 0;
	int py = 0;
	int max_iterations = 1000;
	int color;
	while (py < HEIGHT)
	{
		px = 0;
		int R = 2;
		double y = scale_pixel_to_coord(py, HEIGHT, -R/1.3, R/1.3);
		// double y = scale_pixel_to_coord(py, HEIGHT, min_scale_Y, max_scale_Y);
		while (px < WIDTH)
		{
			// double x = scale_pixel_to_coord(px, WIDTH, min_scale_X, max_scale_X);
			double x = scale_pixel_to_coord(px, WIDTH, -R/1.3, R/1.3);
			// t_compex c = {x, y};
			t_compex c = {-0.8, 0.3};
			t_compex z = {-x, -y};
			// color = calc_m(c, max_iterations);
			color = calc_j(z, c, max_iterations);
			my_put_pixel(&my_display.img_data, px, py, color);
			px++;
		}
		py++;
	}
	mlx_put_image_to_window(my_display.mlx, my_display.win, my_display.img_data.img_ptr, 0, 0);
	mlx_key_hook(my_display.win, close_on_key, &my_display);
	mlx_hook(my_display.win, ON_DESTROY, 0, close_on_event, &my_display);
	mlx_loop(my_display.mlx);
	return (0);
}
