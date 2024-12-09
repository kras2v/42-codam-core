/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:47:55 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/09 22:53:17 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_elem	*ft_find_target_element(t_stack *a, t_stack *b, int i)
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
		target = ft_find_smallest_element(a);
	return (target);
}

static void	ft_assign_target_and_set_distance(t_stack *a, t_stack *b)
{
	int		i;

	i = 0;
	while (i < b->act_size && b->elems[i] != NULL)
	{
		b->elems[i]->target = ft_find_target_element(a, b, i);
		if (b->elems[i] == NULL)
			ft_put_error_and_free(a, b);
		b->elems[i]->distance_to_target = b->elems[i]->position;
		if (!b->elems[i]->above_middle)
			b->elems[i]->distance_to_target
				= b->act_size - b->elems[i]->position;
		if (b->elems[i]->target->above_middle)
			b->elems[i]->distance_to_target += b->elems[i]->target->position;
		else
			b->elems[i]->distance_to_target
				+= a->act_size - b->elems[i]->target->position;
		i++;
	}
}

static void	ft_find_next_to_push(t_stack *b)
{
	int		i;
	long	shortest_distance;
	t_elem	*closest_element;

	i = 0;
	shortest_distance = LONG_MAX;
	while (i < b->act_size && b->elems[i] != NULL)
	{
		if (b->elems[i]->distance_to_target < shortest_distance)
		{
			shortest_distance = b->elems[i]->distance_to_target;
			closest_element = b->elems[i];
		}
		i++;
	}
	closest_element->closest = TRUE;
}

void	ft_refresh_stack_values(t_stack *stack)
{
	int	i;
	int	middle;

	i = 0;
	middle = stack->act_size / 2;
	while (i < stack->act_size && stack->elems[i] != NULL)
	{
		stack->elems[i]->position = i;
		stack->elems[i]->above_middle = stack->elems[i]->position <= middle;
		stack->elems[i]->closest = FALSE;
		i++;
	}
}

void	ft_initialize_stacks(t_stack *a, t_stack *b)
{
	if (is_stack_valid(a))
	{
		ft_refresh_stack_values(a);
	}
	if (is_stack_valid(b))
	{
		ft_refresh_stack_values(b);
	}
	if (is_stack_valid(a) && is_stack_valid(b))
	{
		ft_assign_target_and_set_distance(a, b);
		ft_find_next_to_push(b);
	}
}
