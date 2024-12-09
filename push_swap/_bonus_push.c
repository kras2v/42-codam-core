/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:57:01 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/09 18:52:05 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_bonus_checker.h"

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
		free_all(NULL, a, b);
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
}

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
		free_all(NULL, a, b);
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
}
