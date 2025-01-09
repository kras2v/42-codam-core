/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_initialization.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 11:32:26 by kvalerii          #+#    #+#             */
/*   Updated: 2025/01/09 22:45:51 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>
#include <mlx.h>

static int	close_on_event(t_my_display *my_display)
{
	free_and_exit(my_display, EXIT_SUCCESS, NULL);
	return (0);
}

void	identify_event_handlers(t_my_display *my_display)
{
	mlx_hook(my_display->win, 02, (1L << 0), key_up_events, my_display);
	mlx_hook(my_display->win, 04, (1L << 2), mouse_scroll_events, my_display);
	mlx_hook(my_display->win, 06, (1L << 8), change_julia, my_display);
	mlx_hook(my_display->win, ON_DESTROY, 0L, close_on_event, my_display);
}
