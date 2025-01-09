/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:37:17 by kvalerii          #+#    #+#             */
/*   Updated: 2025/01/09 22:47:08 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>

static void	zoom_in_mouse_positions(int button, int px,
	int py, t_my_display *my_display)
{
	zoom(button, px, py, my_display);
}

int	change_julia(int px, int py, t_my_display *my_display)
{
	if (my_display->img_data.fractol.name == 'J')
	{
		my_display->img_data.fractol.c.real = convert_pixel_to_coordinate(
				px, &(my_display->img_data),
				&(my_display->img_data.fractol), 'x');
		my_display->img_data.fractol.c.imag = convert_pixel_to_coordinate(
				py, &(my_display->img_data),
				&(my_display->img_data.fractol), 'y');
		render_julia(&(my_display->img_data));
		mlx_put_image_to_window(my_display->mlx, my_display->win,
			my_display->img_data.img_ptr, 0, 0);
	}
	return (0);
}

int	mouse_scroll_events(int button, int px, int py, t_my_display *my_display)
{
	if (button == SCROLL_UP || button == SCROLL_DOWN)
	{
		zoom_in_mouse_positions(button, px, py, my_display);
	}
	return (0);
}
