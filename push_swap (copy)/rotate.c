/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:54:51 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/06 13:59:15 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

//(rotate a): Shift up all elements of stack a by 1.
void	ra(t_stack *a)
{
	if (!is_possible_swap_or_rotate(a))
		return ;
	rotate(a);
	ft_printf("ra\n");
}

//(rotate b): Shift up all elements of stack b by 1.
void	rb(t_stack *b)
{
	if (!is_possible_swap_or_rotate(b))
		return ;
	rotate(b);
	ft_printf("rb\n");
}

//ra and rb at the same time.
void	rr(t_stack *a, t_stack *b)
{
	int	is_a_valid;
	int	is_b_valid;
	
	is_a_valid = is_possible_swap_or_rotate(a);
	is_b_valid = is_possible_swap_or_rotate(b);
	if (is_a_valid)
		rotate(a);
	if (is_b_valid)
		rotate(b);
	if (is_a_valid || is_b_valid)
	ft_printf("rr\n");
}
