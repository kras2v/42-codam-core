/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 21:35:39 by valeriia          #+#    #+#             */
/*   Updated: 2024/12/09 19:01:30 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc <= 1)
	{
		return (1);
	}
	genarate_stacks(&a, &b, argc, argv);
	push_swap(a, b, a->max_size + 1);
	free_all_stacks(a, b);
	return (0);
}
