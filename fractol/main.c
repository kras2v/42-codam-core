/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:32:58 by kvalerii          #+#    #+#             */
/*   Updated: 2025/01/10 00:20:29 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#include "libft/libft.h"

static t_complex	get_starting_coordinates(int argc, char **argv,
									t_my_display *my_display)
{
	t_complex	c;

	c.real = -0.4;
	c.imag = 0.6;
	if (argc == 4)
	{
		c.real = ft_fractal_atof(argv[2], my_display);
		c.imag = ft_fractal_atof(argv[3], my_display);
	}
	return (c);
}

static void	show_display(t_my_display *my_display)
{
	mlx_put_image_to_window(my_display->mlx,
		my_display->win,
		my_display->img_data.img_ptr, 0, 0);
	identify_event_handlers(my_display);
	mlx_loop(my_display->mlx);
}

static void	proceed_argv_and_show_display(int argc, char **argv)
{
	t_my_display	my_display;
	t_complex		c;
	int				max_iterations;

	max_iterations = 100;
	if ((argc == 2) && (ft_strcmp(argv[1], "Mandelbrot") == 0))
		initialize_mandelbrot(&my_display, max_iterations);
	else if ((argc == 2) && (ft_strcmp(argv[1], "Newton") == 0))
		initialize_newton(&my_display, max_iterations);
	else if (ft_strcmp(argv[1], "Julia") == 0)
	{
		c = get_starting_coordinates(argc, argv, &my_display);
		initialize_julia(c, &my_display, max_iterations);
	}
	else
		free_and_exit(NULL, 1, "Wrong argument");
	show_display(&my_display);
}

int	main(int argc, char **argv)
{
	if (argc != 2 && argc != 4)
		free_and_exit(NULL, 1, "Wrong amount of arguments");
	proceed_argv_and_show_display(argc, argv);
	return (0);
}
