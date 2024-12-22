#include "fractol.h"

int	close_on_key(int keysym, t_my_display *my_display)
{
	if (keysym == XK_Escape)
	{
		free_and_exit(my_display, 0);
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
	mlx_key_hook(my_display->win, close_on_key, my_display);
	mlx_hook(my_display->win, ON_DESTROY, 0, close_on_event, my_display);
}