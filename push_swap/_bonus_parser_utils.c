/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus_parser_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:47:23 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/09 18:54:23 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_bonus_checker.h"

t_bool	is_value_in_stack(t_stack *a, int value)
{
	int	i;

	if (!is_stack_valid(a))
		return (FALSE);
	i = 0;
	while (i < a->act_size && a->elems[i] != NULL)
	{
		if (a->elems[i]->value == value)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	add_new_element(t_stack *a_stack, int i, long temp)
{
	a_stack->elems[i]->value = temp;
	a_stack->elems[i]->target = NULL;
	a_stack->act_size++;
}

static t_bool	is_digit_and_not_overflow(char *argv, t_bool is_negative)
{
	int		i;
	long	num;

	i = 0;
	num = 0;
	while (argv[i] != '\0')
	{
		if (!ft_isdigit(argv[i]))
			return (FALSE);
		num = num * 10 + (argv[i] - '0');
		if ((!is_negative && num > INT_MAX)
			|| (is_negative && - num < INT_MIN))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	is_argv_i_valid(char *argv)
{
	t_bool	is_negative;

	if (!argv || argv[0] == '\0')
		return (FALSE);
	is_negative = FALSE;
	if (argv[0] == '-')
	{
		is_negative = TRUE;
		if (!ft_isdigit(argv[1]))
			return (FALSE);
	}
	return (is_digit_and_not_overflow(argv + is_negative, is_negative));
}
