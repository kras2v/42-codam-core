/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:47:23 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/06 22:09:06 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_elem_in_array(int elem, t_elem **elems, int index)
{
	int	i;

	if (!elems || index < 0)
		return (false);
	i = 0;
	while (i < index)
	{
		if (elems[i] && elem == (elems[i])->value)
			return (true);
		i++;
	}
	return (false);
}

static t_bool	is_not_overflow(char *argv, t_bool is_negative)
{
	int		i;
	long	num;

	i = 0;
	num = 0;
	while (argv[i] != '\0')
	{
		if (!ft_isdigit(argv[i]))
			return (false);
		num = num * 10 + (argv[i] - '0');
		if ((!is_negative && num > INT_MAX) || (is_negative && - num < INT_MIN))
			return (false);
		i++;
	}
	return (true);
}

t_bool	is_argv_i_valid(char *argv)
{
	t_bool	is_negative;

	if (!argv || argv[0] == '\0')
		return (false);
	is_negative = false;
	if (argv[0] == '-')
	{
		is_negative = true;
		if (!ft_isdigit(argv[1]))
			return (false);
	}
	return (is_not_overflow(argv + is_negative, is_negative));
}

void	add_new_element(t_stack *a_stack, int i, long temp)
{
	a_stack->elems[i]->value = temp;
	a_stack->elems[i]->target = NULL;
	a_stack->act_size++;
}
