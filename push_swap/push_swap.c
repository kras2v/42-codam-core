/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:53:42 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/09 22:46:43 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

static t_bool	ft_compare_to_all_elements(t_stack *a, int el_num, int *medium)
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
	if (ft_abs(smaller - larger) <= 1)
	{
		*medium = a->elems[el_num]->value;
		return (TRUE);
	}
	return (FALSE);
}

static int	ft_find_medium_value(t_stack *a)
{
	int	medium;
	int	i;

	i = 0;
	medium = a->elems[0]->value;
	while (i < a->act_size && a->elems[i] != NULL)
	{
		if (ft_compare_to_all_elements(a, i, &medium))
			break ;
		i++;
	}
	return (medium);
}

static void	ft_push_until_three_elem(t_stack *a, t_stack *b)
{
	int	medium;
	int	i;

	if (!is_stack_valid(a) || !is_stack_valid(b))
		ft_put_error_and_free(a, b);
	while (a->act_size > 3)
	{
		i = 0;
		medium = ft_find_medium_value(a);
		while (i < a->act_size)
		{
			if (a->elems[0]->value < medium)
			{
				ft_pb(a, b);
			}
			else
			{
				ft_ra(a);
			}
			if (a->elems[0]->value >= medium)
				i++;
		}
	}
	ft_sort_three(a);
}

void	ft_push_swap(t_stack *a, t_stack *b, int argc)
{
	t_elem	*smallest;

	if (is_stack_valid(a) && !ft_is_sorted(a))
	{
		if (argc == 4)
			ft_sort_three(a);
		else if (is_stack_valid(b))
		{
			ft_push_until_three_elem(a, b);
			while (b->act_size > 0)
			{
				ft_initialize_stacks(a, b);
				ft_move_element_to_target(a, b);
			}
			ft_initialize_stacks(a, NULL);
			smallest = ft_find_smallest_element(a);
			if (smallest == NULL)
				ft_put_error_and_free(a, b);
			ft_rotate_one_until_closest_on_top(a, smallest, 'a');
		}
	}
}
