/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:00:02 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/09 20:53:09 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_has_min_amount_of_elems(t_stack *stack, int min_size)
{
	return (stack->act_size >= min_size);
}

t_bool	ft_is_possible_swap_or_rotate(t_stack *stack)
{
	return (is_stack_valid(stack) && ft_has_min_amount_of_elems(stack, 2));
}

void	ft_rotate(t_stack *stack)
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

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_reverse_rotate(t_stack *stack)
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
