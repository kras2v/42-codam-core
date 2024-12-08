/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:47:55 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/06 22:45:22 by valeriia         ###   ########.fr       */
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

static void	assign_target_to_each_elem(t_stack *a, t_stack *b)
{
	int		i;

	if (!is_stack_valid(a) || !is_stack_valid(b))
		return ;
	i = 0;
	while (i < b->act_size && b->elems[i] != NULL)
	{
		b->elems[i]->target = find_target_in_a(a, b, i);
		i++;
	}
}

static void	get_push_price(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (i < b->act_size && b->elems[i] != NULL)
	{
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

static void	set_cheapest(t_stack *b)
{
	int		i;
	long	smallest_price;
	t_elem	*smallest_elem;

	if (!b || b->act_size <= 0)
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
	smallest_elem->cheapest = true;
}

void	init_stacks(t_stack *a, t_stack *b)
{
	if (a)
		update_stack_values(a);
	if (b)
		update_stack_values(b);
	if (a && b)
	{
		assign_target_to_each_elem(a, b);
		get_push_price(a, b);
		set_cheapest(b);
	}
}
