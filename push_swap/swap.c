/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:54:07 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/06 13:59:35 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

//(swap a): Swap the first 2 elements at the top of stack a.
void	sa(t_stack *a)
{
	if (!is_possible_swap_or_rotate(a))
		return ;
	swap(&(a->elems[0])->value, &(a->elems[1])->value);
	ft_printf("sa\n");
}

//(swap b): Swap the first 2 elements at the top of stack b.
void	sb(t_stack *b)
{
	if (!is_possible_swap_or_rotate(b))
		return ;
	swap(&(b->elems[0])->value, &(b->elems[1])->value);
	ft_printf("sb\n");
}

//sa and sb at the same time.
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
	if (is_a_valid || is_b_valid)
		ft_printf("ss\n");
}