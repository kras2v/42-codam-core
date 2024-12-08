/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:53:42 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/06 22:45:52 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	update_stack_values(t_stack *stack)
{
	int	i;
	int	middle;

	if (!is_stack_valid(stack))
		return ;
	i = 0;
	middle = stack->act_size / 2;
	while (i < stack->act_size && stack->elems[i] != NULL)
	{
		stack->elems[i]->position = i;
		if (stack->elems[i]->position <= middle)
			stack->elems[i]->above = true;
		else
			stack->elems[i]->above = false;
		stack->elems[i]->cheapest = false;
		i++;
	}
}

static t_bool	ft_is_sorted(t_stack *a)
{
	int	i;

	if (!is_stack_valid(a))
		return (false);
	i = 0;
	while (a->act_size > 1 && i < a->act_size - 1)
	{
		if ((a->elems[i])->value < (a->elems[i + 1])->value)
			i++;
		else
			break ;
	}
	return ((i + 1) == a->act_size);
}

void	push_swap(t_stack *a, t_stack *b, int argc)
{
	if (!ft_is_sorted(a))
	{
		if (argc == 4)
			ft_sort_three(a);
		else
		{
			while (a->act_size > 3)
				pb(a, b);
			ft_sort_three(a);
			while (b->act_size > 0)
			{
				init_stacks(a, b);
				move_from_b_to_a(a, b);
			}
			init_stacks(a, NULL);
			rotate_until_element_on_top(a, find_smallest_element(a), 'a');
		}
	}
}
