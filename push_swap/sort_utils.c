/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:46:49 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/09 22:46:13 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate_both_until_closest_on_top(t_stack *a, t_stack *b,
									t_elem *closest, int reverse)
{
	while (a->elems[0] != closest->target
		&& b->elems[0] != closest)
	{
		if (reverse)
			ft_rrr(a, b);
		else
			ft_rr(a, b);
	}
	ft_refresh_stack_values(a);
	ft_refresh_stack_values(b);
}

t_bool	ft_is_sorted(t_stack *a)
{
	int	i;

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

t_elem	*ft_find_smallest_element(t_stack *stack)
{
	int		i;
	t_elem	*min;

	if (!is_stack_valid(stack) || stack->act_size < 0)
		return (NULL);
	min = stack->elems[0];
	i = 0;
	while (i < stack->act_size)
	{
		if ((stack->elems[i])->value < min->value)
			min = (stack->elems[i]);
		i++;
	}
	return (min);
}

void	ft_rotate_one_until_closest_on_top(t_stack *stack,
									t_elem *element, char stack_name)
{
	while (stack->elems[0] != element)
	{
		if (stack_name == 'a')
		{
			if (element->above_middle)
				ft_ra(stack);
			else
				ft_rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (element->above_middle)
				ft_rb(stack);
			else
				ft_rrb(stack);
		}
	}
}

void	ft_move_element_to_target(t_stack *a, t_stack *b)
{
	t_elem	*closest;
	int		i;

	i = 0;
	while (i < b->act_size && b->elems[i] != NULL && !b->elems[i]->closest)
		i++;
	closest = b->elems[i];
	if (closest->above_middle && closest->target->above_middle)
		ft_rotate_both_until_closest_on_top(a, b, closest, FALSE);
	else if (!closest->above_middle && !closest->target->above_middle)
		ft_rotate_both_until_closest_on_top(a, b, closest, TRUE);
	ft_rotate_one_until_closest_on_top(b, closest, 'b');
	ft_rotate_one_until_closest_on_top(a, closest->target, 'a');
	ft_pa(a, b);
}
