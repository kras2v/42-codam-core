/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:46:49 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/05 15:37:05 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int	find_biggest_value(t_stack *stack)
{
	int	i;
	int	max;

	max = (stack->elems[0])->value;
	i = 0;
	while (i < stack->act_size)
	{
		if ((stack->elems[i])->value > max)
			max = (stack->elems[i])->value;
		i++;
	}
	return (max);
}

t_elem	*find_smallest_element(t_stack *stack)
{
	int		i;
	t_elem	*min;

	if (!stack || stack->act_size <= 0)
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

void ft_sort_three(t_stack *a)
{
	int	max;

	max = find_biggest_value(a);
	if ((a->elems[0])->value == max)
		ra(a);
	else if((a->elems[0])->value == max)
		rra(a);
	if((a->elems[0])->value > (a->elems[1])->value)
		sa(a);
}

int	ft_is_sorted(t_stack *a)
{
	int	i;

	if (!a || !a->elems)
		return 0;
	i = 0;
	while (a->act_size > 1 && i < a->act_size - 1)
	{
		if ((a->elems[i])->value < (a->elems[i + 1])->value)
			i++;
		else 
			break;
	}
	return ((i + 1) == a->act_size);
}

void	init_stacks(t_stack *a, t_stack *b)
{
	set_curent_position(a);
	set_curent_position(b);
	get_target_value(a, b);
	get_push_price(a, b);
	set_cheapest(b);
}

void	get_target_value(t_stack *a, t_stack *b)
{
	int		i;
	t_elem	*target;
	long	best_value;
	int		j;

	if (!is_stack_valid(a) || !is_stack_valid(b))
		return ;
	i = 0;
	while (i < b->act_size && b->elems[i] != NULL)
	{
		j = 0;
		best_value = LONG_MAX;
		while (j < a->act_size && a->elems[j] != NULL)
		{
			if (a->elems[j]->value > b->elems[i]->value && a->elems[j]->value < best_value)
			{
				best_value = a->elems[j]->value;
				target = a->elems[j];
			}
			j++;
		}
		if (best_value == LONG_MAX)
			target = find_smallest_element(a);
		b->elems[i]->target = target;
		i++;
	}
}

void	set_curent_position(t_stack *stack)
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
		i++;
	}
}

void	get_push_price(t_stack *a, t_stack *b)
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
			b->elems[i]->push_price += a->act_size - b->elems[i]->target->position;
		i++;
	}
}

void	set_cheapest(t_stack *b)
{
	int		i;
	long	smallest_price;
	t_elem *smallest_elem;

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

void	rotate_until_element_on_top(t_stack *stack, t_elem *element, char stack_name)
{
	int	i;

	i = 0;
	while (stack->elems[0] != element)
	{
		if (stack_name == 'a')
		{
			if(element->above)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if(element->above)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

void	rotate_both_until_target(t_stack *a, t_stack *b, t_elem *cheapest, int reverse)
{
	int	i;

	i = 0;
	while(a->elems[0] != cheapest->target
		&& b->elems[0] != cheapest)
	{
		if(reverse)
			rrr(a, b);
		else
			rr(a, b);
	}
	set_curent_position(a);
	set_curent_position(b);
}

void	move_from_b_to_a(t_stack *a, t_stack *b)
{
	t_elem	*cheapest;
	int		i;

	if (!a || !b || !a->elems || !b->elems)
		return;
	i = 0;
	while (i < b->act_size && b->elems[i] != NULL && !b->elems[i]->cheapest)
		i++;
	cheapest = b->elems[i];
	if (cheapest->above && cheapest->target->above)
		rotate_both_until_target(a, b, cheapest, false);
	else if (!cheapest->above && !cheapest->target->above)
		rotate_both_until_target(a, b, cheapest, true);
	rotate_until_element_on_top(b, cheapest, 'b');
	rotate_until_element_on_top(a, cheapest->target, 'a');
	pa(a, b);
}