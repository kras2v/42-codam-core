/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:25:46 by valeriia          #+#    #+#             */
/*   Updated: 2025/01/09 15:10:30 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_is_negative(char ch)
{
	if (ch == '-')
		return (1);
	if (ch == '+')
		return (0);
	if (!ft_isdigit(ch))
		return (-1);
	return (0);
}

int	ft_argv_is_double(t_double *_double, const char *argv)
{
	_double->dots = 0;
	if (argv == NULL)
		return (0);
	_double->is_negative = ft_is_negative(*argv);
	if (_double->is_negative)
		argv++;
	while (*argv != '\0')
	{
		if (*argv == '.' && ft_isdigit(*(argv + 1)))
			_double->dots++;
		else if (*argv == ' ')
			break ;
		else if (!ft_isdigit(*argv))
			return (0);
		if (_double->dots > 1)
			return (0);
		argv++;
	}
	return (*argv == '\0');
}

void	free_argv(char *argv[])
{
	int	i;

	i = 0;
	if (argv != NULL)
	{
		while (argv[i] != NULL)
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
}

double	ft_convert_to_double(t_double _double)
{
	double	res;

	if (_double.is_negative)
		_double.before_dot++;
	_double.num_before_dot = ft_atoi(_double.before_dot);
	_double.num_after_dot = ft_atoi(_double.after_dot);
	res = (double)_double.num_before_dot + (double)_double.num_after_dot
		/ pow(10, ft_strlen(_double.after_dot));
	return (res);
}

double	ft_fractal_atof(char *argv, t_my_display *my_display)
{
	t_double	_double;
	double		res;
	char		**dot_part;

	if (!ft_argv_is_double(&_double, argv))
		free_and_exit(my_display, 1, "One of the coordinates has wrong format");
	dot_part = ft_split(argv, '.');
	if (dot_part == NULL)
		free_and_exit(my_display, 1,
			"Error occurate while converting to double");
	_double.before_dot = dot_part[0];
	if (dot_part[1] == NULL)
		res = (double)ft_atoi(_double.before_dot);
	else
	{
		_double.after_dot = dot_part[1];
		res = ft_convert_to_double(_double);
	}
	free_argv(dot_part);
	if (_double.is_negative)
		res *= -1;
	return (res);
}
