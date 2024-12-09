/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus_instructions_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:00:02 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/09 15:36:19 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_bonus_checker.h"

t_bool	has_min_amount_of_elems(t_stack *stack, int min_size)
{
	return (stack->act_size >= min_size);
}

t_bool	is_possible_swap_or_rotate(t_stack *stack)
{
	return (is_stack_valid(stack) && has_min_amount_of_elems(stack, 2));
}

void	rotate(t_stack *stack)
{
	t_elem	*first;
	int		old_index;

	old_index = 0;
	first = (stack->elems[old_index]);
	while (old_index < stack->act_size - 1)
	{
		(stack->elems[old_index]) = (stack->elems[old_index + 1]);
		old_index++;
	}
	stack->elems[stack->act_size - 1] = first;
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	reverse_rotate(t_stack *stack)
{
	t_elem	*last;
	int		old_index;

	old_index = stack->act_size - 1;
	last = (stack->elems[old_index]);
	while (old_index > 0)
	{
		stack->elems[old_index] = stack->elems[old_index - 1];
		old_index--;
	}
	stack->elems[0] = last;
}
