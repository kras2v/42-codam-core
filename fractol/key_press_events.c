/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_events.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:37:43 by kvalerii          #+#    #+#             */
/*   Updated: 2025/01/09 12:08:17 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	zoom_in_center(int keysym, t_my_display *my_display)
{
	int	c_x;
	int	c_y;

	c_x = WIDTH / 2;
	c_y = HEIGHT / 2;
	zoom(keysym, c_x, c_y, my_display);
	return (1);
}

static int	shifting(int code, t_my_display *my_display)
{
	double	x_shift;
	double	y_shift;
	double	max_move_x;
	double	max_move_y;
	t_scale	new_scale;

	x_shift = 0;
	y_shift = 0;
	max_move_x = (my_display->img_data.fractol.scale.max_real
			- my_display->img_data.fractol.scale.min_real) * 0.05;
	max_move_y = (my_display->img_data.fractol.scale.max_imag
			- my_display->img_data.fractol.scale.min_imag) * 0.05;
	if (code == XK_Up)
		y_shift = -max_move_y;
	else if (code == XK_Down)
		y_shift = max_move_y;
	else if (code == XK_Left)
		x_shift = -max_move_x;
	else if (code == XK_Right)
		x_shift = max_move_x;
	new_scale = create_scale(y_shift, y_shift, x_shift, x_shift);
	change_scale_parametrs(&(my_display->img_data.fractol.scale), new_scale);
	execute_fractal_rendering(&(my_display->img_data));
	return (1);
}

static int	color_range_shift(t_my_display *my_display)
{
	if (my_display->img_data.fractol.color_type == 'S')
		my_display->img_data.fractol.color_type = 'R';
	else
		my_display->img_data.fractol.color_type = 'S';
	execute_fractal_rendering(&(my_display->img_data));
	return (1);
}

int	key_up_events(int keysym, t_my_display *my_display)
{
	int	display_changed;

	display_changed = 0;
	if (keysym == XK_Escape)
		free_and_exit(my_display, 0, NULL);
	else if (keysym == XK_Up || keysym == XK_Down
		|| keysym == XK_Left || keysym == XK_Right)
		display_changed = shifting(keysym, my_display);
	else if (keysym == XK_equal || keysym == XK_minus)
		display_changed = zoom_in_center(keysym, my_display);
	else if (keysym == XK_C || keysym == XK_c)
		display_changed = color_range_shift(my_display);
	if (display_changed)
	{
		mlx_put_image_to_window(my_display->mlx, my_display->win,
			my_display->img_data.img_ptr, 0, 0);
	}
	return (0);
}
