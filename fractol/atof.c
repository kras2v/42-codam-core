/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 12:25:46 by valeriia          #+#    #+#             */
/*   Updated: 2024/12/26 21:18:09 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

typedef struct s_double{
	char *before_dot;
	char *after_dot;
	char *after_e;
	int is_negative;
	int e_is_negative;
	int num_before_dot;
	int num_after_dot;
	int num_after_e;
	int dots;
	int Es;
} t_double;


void ft_skip_spaces(const char **argv)
{
	while (**argv != '\0' && **argv == ' ')
		(*argv)++;
}

int ft_is_negative(char ch)
{
	if (ch == '-')
		return (1);
	if (ch == '+')
		return (0);
	if (!ft_isdigit(ch))
		return (-1);
	return (0);
}

int move_if_negative(int *is_negative, const char **argv)
{
	*is_negative = ft_is_negative(**argv);
	if (*is_negative < 0)
		return (0);
	if (ft_isdigit((*argv)[1]))
		(*argv)++;
	return (1);
}

int ft_argv_is_double(t_double *_double, const char *argv)
{
	_double->dots = 0;
	_double->Es = 0;
	_double->e_is_negative = 0;
	if (argv == NULL)
		return (0);
	ft_skip_spaces(&argv);
	if (!move_if_negative(&_double->is_negative, &argv))
		return (0);
	while (*argv != '\0')
	{
		if (*argv == '.' && ft_isdigit(*(argv + 1)))
			_double->dots++;
		else if ((*argv == 'e' || *argv == 'E'))
		{
			_double->Es++;
			argv++;
			if (!move_if_negative(&_double->e_is_negative, &argv))
				return (0);
			if (!ft_isdigit(*argv))
				return (0);
		}
		else if (*argv == ' ')
			break;
		else if (!ft_isdigit(*argv))
			return (0);
		if (_double->dots > 1 || _double->Es > 1)
			return (0);
		argv++;
	}
	ft_skip_spaces(&argv);
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

double ft_convert_to_double(t_double _double)
{
	double res;

	if (_double.is_negative)
		_double.before_dot++;
	_double.num_before_dot = ft_atoi(_double.before_dot);
	_double.num_after_dot = ft_atoi(_double.after_dot);
	res = (double)_double.num_before_dot + (double)_double.num_after_dot / pow(10, ft_strlen(_double.after_dot));
	if (_double.Es)
	{
		_double.num_after_e = ft_atoi(_double.after_e);
		res *= pow(10, _double.num_after_e);
	}
	return (res);
}

double parse_e(t_double _double, const char *dot_part)
{
	char	**e_part;
	double res;

	e_part = ft_split(dot_part, 'e');
	if (e_part[1] == NULL)
	{
		free_argv(e_part);
		e_part = ft_split(dot_part, 'E');
		if (e_part == NULL || e_part[1] == NULL)
			return (0);
	}
	_double.after_dot = e_part[0];
	_double.after_e = e_part[1];
	res =  ft_convert_to_double(_double);
	return (res);
}

double ft_atof(char *argv, t_my_display *my_display)
{
	t_double	_double;
	double		res;
	char		**dot_part;

	if (!ft_argv_is_double(&_double, argv))
		free_and_exit(my_display, 1);
	dot_part = ft_split(argv, '.');
	if (dot_part == NULL)
		free_and_exit(my_display, 1);
	_double.before_dot = dot_part[0];
	if (_double.Es == 1)
		res = parse_e(_double, dot_part[1]);
	else
	{
		if (dot_part[1] == NULL)
			res = (double)ft_atoi(_double.before_dot);
		else
		{
			_double.after_dot = dot_part[1];
			res = ft_convert_to_double(_double);
		}
	}
	free_argv(dot_part);
	if (_double.is_negative)
		res *= -1;
	return (res);
}
