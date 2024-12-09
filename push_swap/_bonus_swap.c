/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:54:07 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/09 16:22:25 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_bonus_checker.h"

void	sa(t_stack *a)
{
	if (!is_possible_swap_or_rotate(a))
		return ;
	swap(&(a->elems[0])->value, &(a->elems[1])->value);
}

void	sb(t_stack *b)
{
	if (!is_possible_swap_or_rotate(b))
		return ;
	swap(&(b->elems[0])->value, &(b->elems[1])->value);
}

void	ss(t_stack *a, t_stack *b)
{
	int	is_a_valid;
	int	is_b_valid;

	is_a_valid = is_possible_swap_or_rotate(a);
	is_b_valid = is_possible_swap_or_rotate(b);
	if (is_a_valid)
		swap(&(a->elems[0])->value, &(a->elems[1])->value);
	if (is_b_valid)
		swap(&(b->elems[0])->value, &(b->elems[1])->value);
}
