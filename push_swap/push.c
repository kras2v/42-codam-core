/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:57:01 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/06 22:13:31 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//(push a): Take the first element at the top of b and put it at the top of a.
void	pa(t_stack *a, t_stack *b)
{
	int	i;

	if (!is_stack_valid(a)
		|| !is_stack_valid(b)
		|| !has_min_amount_of_elems(b, 1))
		return ;
	i = 0;
	while (a->elems[i] != NULL)
		i++;
	a->elems[i] = malloc(sizeof(t_elem));
	if (!a->elems[i])
	{
		free_all_stacks(a, b);
		ft_put_error();
	}
	a->elems[i]->target = NULL;
	a->act_size++;
	reverse_rotate(a);
	(a->elems[0])->value = (b->elems[0])->value;
	rotate(b);
	free(b->elems[b->act_size - 1]);
	b->elems[b->act_size - 1] = NULL;
	b->act_size--;
	ft_printf("pa\n");
}

//(push b): Take the first element at the top of a and put it at the top of b.
void	pb(t_stack *a, t_stack *b)
{
	int	i;

	if (!is_stack_valid(a)
		|| !is_stack_valid(b)
		|| !has_min_amount_of_elems(a, 1))
		return ;
	i = 0;
	while (b->elems[i] != NULL)
		i++;
	b->elems[i] = malloc(sizeof(t_elem));
	if (!b->elems[i])
	{
		free_all_stacks(a, b);
		ft_put_error();
		return ;
	}
	b->elems[i]->target = NULL;
	b->act_size++;
	reverse_rotate(b);
	(b->elems[0])->value = (a->elems[0])->value;
	rotate(a);
	free(a->elems[a->act_size - 1]);
	a->elems[a->act_size - 1] = NULL;
	a->act_size--;
	ft_printf("pb\n");
}
