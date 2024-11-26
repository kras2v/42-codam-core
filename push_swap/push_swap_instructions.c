/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:54:30 by kvalerii          #+#    #+#             */
/*   Updated: 2024/11/26 15:01:59 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Swap the first 2 elements at the top of stack a
void	sa(int **a)
{
	int	temp;

	temp = (*a)[0];
	(*a)[0] = (*a)[1];
	(*a)[1] = temp;
	ft_printf("sa");
}
//Swap the first 2 elements at the top of stack b
void	sb(int **b)
{
	int	temp;

	temp = (*b)[0];
	(*b)[0] = (*b)[1];
	(*b)[1] = temp;
	ft_printf("sb");
}
//sa and sb at the same time
void	ss(int **a, int **b)
{
	int	temp;

	temp = (*a)[0];
	(*a)[0] = (*a)[1];
	(*a)[1] = temp;
	temp = (*b)[0];
	(*b)[0] = (*b)[1];
	(*b)[1] = temp;
	ft_printf("ss");
}
// void pa(int **a, int **b)
// {
	
// }