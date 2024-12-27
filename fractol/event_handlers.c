#include "fractol.h"

void shifting(int code, t_my_display *my_display)
{
	double x_scale;
	double y_scale;
	double max_move_x;
	double max_move_y;

	x_scale = 0;
	y_scale = 0;
	max_move_x = (my_display->img_data.fractol.scale.max_scale_X - my_display->img_data.fractol.scale.min_scale_X) * 0.05;
	max_move_y = (my_display->img_data.fractol.scale.max_scale_Y - my_display->img_data.fractol.scale.min_scale_Y) * 0.05;
	if (code == XK_Up)
	{
		y_scale = -max_move_y;
		x_scale = 0;
	}
	else if (code == XK_Down)
	{
		y_scale = max_move_y;
		x_scale = 0;
	}
	else if (code == XK_Left)
	{
		y_scale = 0;
		x_scale = -max_move_x;
	}
	else if (code == XK_Right)
	{
		y_scale = 0;
		x_scale = max_move_x;
	}
	my_display->img_data.fractol.scale.min_scale_Y += y_scale;
	my_display->img_data.fractol.scale.max_scale_Y += y_scale;
	my_display->img_data.fractol.scale.min_scale_X += x_scale;
	my_display->img_data.fractol.scale.max_scale_X += x_scale;
	if(my_display->img_data.fractol.name == 'M')
		mandelbrot(&(my_display->img_data));
	else if(my_display->img_data.fractol.name == 'J')
		julia(&(my_display->img_data));
	mlx_put_image_to_window(my_display->mlx, my_display->win, my_display->img_data.img_ptr, 0, 0);
}

void zoom_in_centre(int code, t_my_display *my_display)
{
	double max_move_x;
	double max_move_y;

	max_move_x = 0;
	max_move_y = 0;
	if (code == XK_equal || code == SCROLL_UP)
	{
		max_move_x = -(my_display->img_data.fractol.scale.max_scale_X - my_display->img_data.fractol.scale.min_scale_X) * 0.05;
		max_move_y = -(my_display->img_data.fractol.scale.max_scale_Y - my_display->img_data.fractol.scale.min_scale_Y) * 0.05;
	}
	else if (code == XK_minus || code == SCROLL_DOWN)
	{
		max_move_x = (my_display->img_data.fractol.scale.max_scale_X - my_display->img_data.fractol.scale.min_scale_X) * 0.05;
		max_move_y = (my_display->img_data.fractol.scale.max_scale_Y - my_display->img_data.fractol.scale.min_scale_Y) * 0.05;
	}
	my_display->img_data.fractol.scale.max_scale_X += max_move_x;
	my_display->img_data.fractol.scale.max_scale_Y += max_move_y;
	my_display->img_data.fractol.scale.min_scale_X -= max_move_x;
	my_display->img_data.fractol.scale.min_scale_Y -= max_move_y;
	if(my_display->img_data.fractol.name == 'M')
		mandelbrot(&(my_display->img_data));
	else if(my_display->img_data.fractol.name == 'J')
		julia(&(my_display->img_data));
	mlx_put_image_to_window(my_display->mlx, my_display->win, my_display->img_data.img_ptr, 0, 0);
}

int change_julia(int x, int y, t_my_display *my_display)
{
	if (my_display->img_data.fractol.name == 'J')
	{
		my_display->img_data.fractol.c.real = convert_pixel_to_coordinate(x, &(my_display->img_data), 'x');
		my_display->img_data.fractol.c.imag = convert_pixel_to_coordinate(y, &(my_display->img_data), 'y');
		julia(&(my_display->img_data));
		mlx_put_image_to_window(my_display->mlx, my_display->win, my_display->img_data.img_ptr, 0, 0);
		return (0);
	}
	return (0);
}

int	key_up_events(int keysym, t_my_display *my_display)
{
	if (keysym == XK_Escape)
	{
		free_and_exit(my_display, 0);
		return (0);
	}
	if (keysym == XK_Up || keysym == XK_Down || keysym == XK_Left || keysym == XK_Right)
	{
		shifting(keysym, my_display);
		return (0);
	}
	if (keysym == XK_equal || keysym == XK_minus)
	{
		zoom_in_centre(keysym, my_display);
		return (0);
	}
	return (1);
}

int	mouse_scroll_events(int button, int x, int y, t_my_display *my_display)
{
	(void)x;
	(void)y;
	if (button == SCROLL_UP || button == SCROLL_DOWN)
	{
		zoom_in_centre(button, my_display);
		return (0);
	}
	if (button == LEFT_CLICK)
	{
		change_julia(x, y, my_display);
		return (0);
	}
	return (1);
}

int	close_on_event(t_my_display *my_display)
{
	free_and_exit(my_display, 0);
	return (0);
}

void	identify_event_handlers(t_my_display *my_display)
{
	mlx_key_hook(my_display->win, key_up_events, my_display);
	// mlx_mouse_hook(my_display->win, mouse_scroll_events, my_display);
	mlx_hook(my_display->win, 06, (1L<<13), change_julia, my_display);
	mlx_hook(my_display->win, ON_DESTROY, (1L<<6), close_on_event, my_display);
}