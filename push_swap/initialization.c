/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:47:55 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/09 17:18:44 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_elem	*find_target_in_a(t_stack *a, t_stack *b, int i)
{
	t_elem	*target;
	long	best_value;
	int		j;

	j = 0;
	best_value = LONG_MAX;
	while (j < a->act_size && a->elems[j] != NULL)
	{
		if (a->elems[j]->value > b->elems[i]->value
			&& a->elems[j]->value < best_value)
		{
			best_value = a->elems[j]->value;
			target = a->elems[j];
		}
		j++;
	}
	if (best_value == LONG_MAX)
		target = find_smallest_element(a);
	return (target);
}

static void	assign_target_and_set_price(t_stack *a, t_stack *b)
{
	int		i;

	if (!is_stack_valid(a) || !is_stack_valid(b))
		return ;
	i = 0;
	while (i < b->act_size && b->elems[i] != NULL)
	{
		b->elems[i]->target = find_target_in_a(a, b, i);
		b->elems[i]->push_price = b->elems[i]->position;
		if (!b->elems[i]->above)
			b->elems[i]->push_price = b->act_size - b->elems[i]->position;
		if (b->elems[i]->target->above)
			b->elems[i]->push_price += b->elems[i]->target->position;
		else
			b->elems[i]->push_price
				+= a->act_size - b->elems[i]->target->position;
		i++;
	}
}

static void	find_cheapest_elem(t_stack *b)
{
	int		i;
	long	smallest_price;
	t_elem	*smallest_elem;

	if (!is_stack_valid(b))
		return ;
	i = 0;
	smallest_price = LONG_MAX;
	while (i < b->act_size && b->elems[i] != NULL)
	{
		if (b->elems[i]->push_price < smallest_price)
		{
			smallest_price = b->elems[i]->push_price;
			smallest_elem = b->elems[i];
		}
		i++;
	}
	smallest_elem->cheapest = TRUE;
}

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
		stack->elems[i]->above = stack->elems[i]->position <= middle;
		stack->elems[i]->cheapest = FALSE;
		i++;
	}
}

void	init_stacks(t_stack *a, t_stack *b)
{
	if (a)
		update_stack_values(a);
	if (b)
		update_stack_values(b);
	if (a && b)
	{
		assign_target_and_set_price(a, b);
		find_cheapest_elem(b);
	}
}
