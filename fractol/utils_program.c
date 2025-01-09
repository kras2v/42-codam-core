/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 12:12:14 by kvalerii          #+#    #+#             */
/*   Updated: 2025/01/09 23:20:33 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"
#include <mlx.h>

t_scale	create_scale(double max_imag, double min_imag,
	double max_real, double min_real)
{
	t_scale	scale;

	scale.max_imag = max_imag;
	scale.min_imag = min_imag;
	scale.max_real = max_real;
	scale.min_real = min_real;
	return (scale);
}

static void	display_info(void)
{
	ft_printf("Usage: ./program <parameter> [x y]\n");
	ft_printf("\n");
	ft_printf("Available parameters:\n");
	ft_printf("  Mandelbrot		Generate the Mandelbrot set.\n");
	ft_printf("  Newton		Generate the Mandelbrot set.\n");
	ft_printf("  Julia			"
		"Generate the Julia set with default parameters (0.4, -0.6).\n");
	ft_printf("  Julia <x> <y>		"
		"Generate the Julia set with custom parameters <x> and <y>.\n");
	ft_printf("\n");
	ft_printf("Example usage:\n");
	ft_printf("  ./fractol Mandelbrot		Generate Mandelbrot set.\n");
	ft_printf("  ./fractol Newton		Generate Newton set.\n");
	ft_printf("  ./fractol Julia		"
		"Generate Julia set with default parameters.\n");
	ft_printf("  ./fractol Julia 0.355 0.355	"
		"Generate Julia set with x = 0.355, y = 0.355.\n");
}

static void	send_error_msg(char *msg)
{
	if (msg != NULL)
	{
		ft_putendl_fd(msg, 2);
		display_info();
	}
}

void	free_and_exit(t_my_display *my_display, int exit_code, char *msg)
{
	if (my_display && my_display->mlx != NULL)
	{
		if (my_display->img_data.img_ptr != NULL)
			mlx_destroy_image(my_display->mlx, my_display->img_data.img_ptr);
		if (my_display->win != NULL)
			mlx_destroy_window(my_display->mlx, my_display->win);
		mlx_destroy_display(my_display->mlx);
		free(my_display->mlx);
	}
	send_error_msg(msg);
	exit(exit_code);
}
