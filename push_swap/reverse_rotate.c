/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:54:51 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/06 14:00:36 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

//rra (reverse rotate a): Shift down all elements of stack a by 1
void	rra(t_stack *a)
{
	if (!is_possible_swap_or_rotate(a))
		return ;
	reverse_rotate(a);
	ft_printf("rra\n");
}

//rrb (reverse rotate b): Shift down all elements of stack b by 1
void	rrb(t_stack *b)
{
	if (!is_possible_swap_or_rotate(b))
		return ;
	reverse_rotate(b);
	ft_printf("rrb\n");
}

//rrr : rra and rrb at the same time
void	rrr(t_stack *a, t_stack *b)
{
	int	is_a_valid;
	int	is_b_valid;
	
	is_a_valid = is_possible_swap_or_rotate(a);
	is_b_valid = is_possible_swap_or_rotate(b);
	if (is_a_valid)
		reverse_rotate(a);
	if (is_b_valid)
		reverse_rotate(b);
	if (is_a_valid || is_b_valid)
	ft_printf("rrr\n");
}