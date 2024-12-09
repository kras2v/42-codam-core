/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:53:42 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/09 17:18:46 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

static t_bool	compare_with_all_elements(t_stack *a, int el_num, int *medium)
{
	int	j;
	int	larger;
	int	smaller;

	j = 0;
	larger = 0;
	smaller = 0;
	while (j < a->act_size && a->elems[j] != NULL)
	{
		if (a->elems[j]->value > a->elems[el_num]->value)
			larger++;
		else if (a->elems[j]->value < a->elems[el_num]->value)
			smaller++;
		j++;
	}
	if (_abs(smaller - larger) <= 1)
	{
		*medium = a->elems[el_num]->value;
		return (TRUE);
	}
	return (FALSE);
}

static int	find_medium_value(t_stack *a)
{
	int	medium;
	int	i;

	i = 0;
	medium = a->elems[0]->value;
	while (i < a->act_size && a->elems[i] != NULL)
	{
		if (compare_with_all_elements(a, i, &medium))
			break ;
		i++;
	}
	return (medium);
}

static void	move_to_b(t_stack *a, t_stack *b)
{
	int	medium;
	int	i;

	while (a->act_size > 3)
	{
		i = 0;
		medium = find_medium_value(a);
		while (i < a->act_size)
		{
			if (a->elems[0]->value < medium)
			{
				pb(a, b);
			}
			else
			{
				ra(a);
			}
			if (a->elems[0]->value >= medium)
				i++;
		}
	}
	ft_sort_three(a);
}

void	push_swap(t_stack *a, t_stack *b, int argc)
{
	if (!ft_is_sorted(a))
	{
		if (argc == 4)
			ft_sort_three(a);
		else
		{
			move_to_b(a, b);
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
