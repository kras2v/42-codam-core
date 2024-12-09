/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:54:51 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/09 16:23:02 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_bonus_checker.h"

void	ra(t_stack *a)
{
	if (!is_possible_swap_or_rotate(a))
		return ;
	rotate(a);
}

void	rb(t_stack *b)
{
	if (!is_possible_swap_or_rotate(b))
		return ;
	rotate(b);
}

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
}
