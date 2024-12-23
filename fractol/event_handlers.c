#include "fractol.h"

void shifting(int keysym, t_my_display *my_display)
{
	if (keysym == XK_Up)
	{
		my_display->img_data.scale.min_scale_Y += 0.2;
		my_display->img_data.scale.max_scale_Y += 0.2;
	}
	else if (keysym == XK_Down)
	{
		my_display->img_data.scale.min_scale_Y -= 0.2;
		my_display->img_data.scale.max_scale_Y -= 0.2;
	}
	else if (keysym == XK_Left)
	{
		my_display->img_data.scale.min_scale_X += 0.2;
		my_display->img_data.scale.max_scale_X += 0.2;
	}
	else if (keysym == XK_Right)
	{
		my_display->img_data.scale.min_scale_X -= 0.2;
		my_display->img_data.scale.max_scale_X -= 0.2;
	}
	if(ft_strcmp(my_display->img_data.fractol, "Mandelbrot") == 0)
		mandelbrot(&(my_display->img_data));
	else if(ft_strcmp(my_display->img_data.fractol, "Julia") == 0)
		julia(&(my_display->img_data));
	mlx_put_image_to_window(my_display->mlx, my_display->win, my_display->img_data.img_ptr, 0, 0);
}

int	key_up_events(int keysym, t_my_display *my_display)
{
	if (keysym == XK_Escape)
	{
		free_and_exit(my_display, 0);
		return (0);
	}
	if (keysym == XK_Up || keysym == XK_Down || keysym == XK_Left || keysym == XK_Right)
		shifting(keysym, my_display);
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
	mlx_hook(my_display->win, ON_DESTROY, 0, close_on_event, my_display);
}