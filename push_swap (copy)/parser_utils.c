/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:47:23 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/05 14:13:55 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/parser_utils.h"

int	is_elem_in_array(int elem, t_elem **elems, int index)
{
	int	i;

	if (!elems || index < 0)
		return (0);
	i = 0;
	while (i < index)
	{
		if (elems[i] && elem ==  (elems[i])->value)
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_valid_sign(char c, int j)
{
	return (j == 0 && (c == '-' || c == '+'));
}

int	is_argv_i_valid(char *argv)
{
	int		i;
	long	num;
	int		is_negative;

	if (!argv || argv[0] == '\0') // Empty string check
		return (0);
	i = 0;
	is_negative = 0;
	if (ft_is_valid_sign(argv[i], i))
	{
		if (argv[i] == '-')
			is_negative = 1;
		i++;
	}
	num = 0;
	while (argv[i] != '\0')
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		num = num * 10 + (argv[i] - '0');
		if ((!is_negative && num > INT_MAX) 
			|| (is_negative && -num < INT_MIN))
			return (0);
		i++;
	}
	if ((is_negative == 1 && i == 1)
		|| (is_negative == 0 && i == 0))
		return (0);
	return (1);
}