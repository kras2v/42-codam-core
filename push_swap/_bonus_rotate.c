/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:54:51 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/09 20:54:27 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_bonus_checker.h"

void	ft_ra(t_stack *a)
{
	if (!ft_is_possible_swap_or_rotate(a))
		return ;
	ft_rotate(a);
}

void	ft_rb(t_stack *b)
{
	if (!ft_is_possible_swap_or_rotate(b))
		return ;
	ft_rotate(b);
}

void	ft_rr(t_stack *a, t_stack *b)
{
	int	is_a_valid;
	int	is_b_valid;

	is_a_valid = ft_is_possible_swap_or_rotate(a);
	is_b_valid = ft_is_possible_swap_or_rotate(b);
	if (is_a_valid)
		ft_rotate(a);
	if (is_b_valid)
		ft_rotate(b);
}
