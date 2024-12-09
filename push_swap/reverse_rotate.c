/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:54:51 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/09 21:09:52 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack *a)
{
	if (!ft_is_possible_swap_or_rotate(a))
		return ;
	ft_reverse_rotate(a);
	ft_printf("rra\n");
}

void	ft_rrb(t_stack *b)
{
	if (!ft_is_possible_swap_or_rotate(b))
		return ;
	ft_reverse_rotate(b);
	ft_printf("rrb\n");
}

void	ft_rrr(t_stack *a, t_stack *b)
{
	int	is_a_valid;
	int	is_b_valid;

	is_a_valid = ft_is_possible_swap_or_rotate(a);
	is_b_valid = ft_is_possible_swap_or_rotate(b);
	if (is_a_valid)
		ft_reverse_rotate(a);
	if (is_b_valid)
		ft_reverse_rotate(b);
	if (is_a_valid || is_b_valid)
		ft_printf("rrr\n");
}
