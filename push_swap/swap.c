/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:54:07 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/09 21:18:05 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack *a)
{
	if (!ft_is_possible_swap_or_rotate(a))
		return ;
	ft_swap(&(a->elems[0])->value, &(a->elems[1])->value);
	ft_printf("sa\n");
}

void	ft_sb(t_stack *b)
{
	if (!ft_is_possible_swap_or_rotate(b))
		return ;
	ft_swap(&(b->elems[0])->value, &(b->elems[1])->value);
	ft_printf("sb\n");
}

void	ft_ss(t_stack *a, t_stack *b)
{
	int	is_a_valid;
	int	is_b_valid;

	is_a_valid = ft_is_possible_swap_or_rotate(a);
	is_b_valid = ft_is_possible_swap_or_rotate(b);
	if (is_a_valid)
		ft_swap(&(a->elems[0])->value, &(a->elems[1])->value);
	if (is_b_valid)
		ft_swap(&(b->elems[0])->value, &(b->elems[1])->value);
	if (is_a_valid || is_b_valid)
		ft_printf("ss\n");
}
