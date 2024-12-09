/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:54:55 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/09 22:29:01 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_find_biggest_value(t_stack *stack)
{
	int	i;
	int	max;

	max = (stack->elems[0])->value;
	i = 0;
	while (i < stack->act_size)
	{
		if ((stack->elems[i])->value > max)
		{
			max = (stack->elems[i])->value;
		}
		i++;
	}
	return (max);
}

void	ft_sort_three(t_stack *a)
{
	int	max;

	max = ft_find_biggest_value(a);
	if ((a->elems[0])->value == max)
	{
		ft_ra(a);
	}
	else if ((a->elems[1])->value == max)
	{
		ft_rra(a);
	}
	if ((a->elems[0])->value > (a->elems[1])->value)
	{
		ft_sa(a);
	}
}
