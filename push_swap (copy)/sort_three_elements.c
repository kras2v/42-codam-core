/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:54:55 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/06 14:55:22 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

static int	find_biggest_value(t_stack *stack)
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

void ft_sort_three(t_stack *a)
{
	int	max;

	max = find_biggest_value(a);
	if ((a->elems[0])->value == max)
		ra(a);
	else if((a->elems[1])->value == max)
		rra(a);
	if((a->elems[0])->value > (a->elems[1])->value)
		sa(a);
}