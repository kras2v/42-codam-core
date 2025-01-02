#include "fractol.h"

void shifting(int code, t_my_display *my_display)
{
	double x_shift_dist;
	double y_shift_dist;
	double max_move_x;
	double max_move_y;

	x_shift_dist = 0;
	y_shift_dist = 0;
	max_move_x = (my_display->img_data.fractol.scale.max_scale_X - my_display->img_data.fractol.scale.min_scale_X) * 0.05;
	max_move_y = (my_display->img_data.fractol.scale.max_scale_Y - my_display->img_data.fractol.scale.min_scale_Y) * 0.05;
	if (code == XK_Up)
	{
		y_shift_dist = -max_move_y;
		x_shift_dist = 0;
	}
	else if (code == XK_Down)
	{
		y_shift_dist = max_move_y;
		x_shift_dist = 0;
	}
	else if (code == XK_Left)
	{
		y_shift_dist = 0;
		x_shift_dist = -max_move_x;
	}
	else if (code == XK_Right)
	{
		y_shift_dist = 0;
		x_shift_dist = max_move_x;
	}
	my_display->img_data.fractol.scale.min_scale_Y += y_shift_dist;
	my_display->img_data.fractol.scale.max_scale_Y += y_shift_dist;
	my_display->img_data.fractol.scale.min_scale_X += x_shift_dist;
	my_display->img_data.fractol.scale.max_scale_X += x_shift_dist;
	if(my_display->img_data.fractol.name == 'M')
		mandelbrot(&(my_display->img_data));
	else if(my_display->img_data.fractol.name == 'J')
		julia(&(my_display->img_data));
	else if(my_display->img_data.fractol.name == 'N')
		newton(&(my_display->img_data));
	mlx_put_image_to_window(my_display->mlx, my_display->win, my_display->img_data.img_ptr, 0, 0);
}

void zoom(int btn, int x, int y, t_my_display *my_display)
{
	double xRatio;
	double yRatio;
	double dReal;
	double dImag;
	double ddReal;
	double ddImag;

	ddReal = 0;
	ddImag = 0;
	xRatio = (double)x / (double)my_display->img_data.size.max_px;
	yRatio = (double)y / (double)my_display->img_data.size.max_py;
	dReal = my_display->img_data.fractol.scale.max_scale_X - my_display->img_data.fractol.scale.min_scale_X;
	dImag = my_display->img_data.fractol.scale.max_scale_Y - my_display->img_data.fractol.scale.min_scale_Y;
	if (btn == SCROLL_UP || btn == XK_equal)
	{
		ddReal = (0.3 * dReal) - dReal;
		ddImag = (0.3 * dImag) - dImag;
	}
	else if (btn == SCROLL_DOWN || btn == XK_minus)
	{
		ddReal = ((1/0.3) * dReal) - dReal;
		ddImag = ((1/0.3) * dImag) - dImag;
	}
	my_display->img_data.fractol.scale.min_scale_X = my_display->img_data.fractol.scale.min_scale_X - (ddReal * xRatio);
	my_display->img_data.fractol.scale.max_scale_X = my_display->img_data.fractol.scale.max_scale_X + (ddReal * (1 - xRatio));
	my_display->img_data.fractol.scale.max_scale_Y = my_display->img_data.fractol.scale.max_scale_Y + (ddImag * (1 - yRatio));
	my_display->img_data.fractol.scale.min_scale_Y = my_display->img_data.fractol.scale.min_scale_Y - (ddImag * yRatio);
	if(my_display->img_data.fractol.name == 'M')
		mandelbrot(&(my_display->img_data));
	else if(my_display->img_data.fractol.name == 'J')
		julia(&(my_display->img_data));
	else if(my_display->img_data.fractol.name == 'N')
		newton(&(my_display->img_data));
	mlx_put_image_to_window(my_display->mlx, my_display->win, my_display->img_data.img_ptr, 0, 0);
}

int show_coordinates(int button, int px, int py, t_my_display *my_display)
{
	double x;
	double y;

	if (button == LEFT_CLICK)
	{
		x = convert_pixel_to_coordinate(px, &(my_display->img_data), 'x');
		y = convert_pixel_to_coordinate(py, &(my_display->img_data), 'y');
		ft_printf("Pixels: (%d, %d)\tCoordinates: (%f, %f)\n", px, py, x, y);
	}
	return (1);
}

int change_julia(int px, int py, t_my_display *my_display)
{
	if (my_display->img_data.fractol.name == 'J')
	{
		my_display->img_data.fractol.c.real = convert_pixel_to_coordinate(px, &(my_display->img_data), 'x');
		my_display->img_data.fractol.c.imag = convert_pixel_to_coordinate(py, &(my_display->img_data), 'y');
		julia(&(my_display->img_data));
		mlx_put_image_to_window(my_display->mlx, my_display->win, my_display->img_data.img_ptr, 0, 0);
		return (0);
	}
	return (1);
}

int	key_up_events(int keysym, t_my_display *my_display)
{
	if (keysym == XK_Escape)
	{
		free_and_exit(my_display, 0, NULL);
		return (0);
	}
	if (keysym == XK_Up || keysym == XK_Down || keysym == XK_Left || keysym == XK_Right)
	{
		shifting(keysym, my_display);
		return (0);
	}
	if (keysym == XK_equal || keysym == XK_minus)
	{
		zoom(keysym, WIDTH/2, HEIGHT/2, my_display);
		return (0);
	}
	return (1);
}

int	mouse_scroll_events(int button, int px, int py, t_my_display *my_display)
{
	if (button == SCROLL_UP || button == SCROLL_DOWN)
	{
		zoom(button, px, py, my_display);
		return (0);
	}
	return (1);
}

int	close_on_event(t_my_display *my_display)
{
	free_and_exit(my_display, 0, NULL);
	return (0);
}

void	identify_event_handlers(t_my_display *my_display)
{
	mlx_hook(my_display->win, 02, (1L<<0), key_up_events, my_display);
	mlx_hook(my_display->win, 04, (1L<<2), mouse_scroll_events, my_display);
	mlx_hook(my_display->win, 05, (1L<<3), show_coordinates, my_display);
	mlx_hook(my_display->win, 06, (1L<<8), change_julia, my_display);
	mlx_hook(my_display->win, ON_DESTROY, 0L, close_on_event, my_display);
}