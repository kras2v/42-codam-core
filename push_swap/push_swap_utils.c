/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:52:13 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/06 14:53:24 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

//!REMOVE
void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->act_size && stack->elems[i] != NULL)
	{
		ft_printf("%d\t", (stack->elems[i])->value);
		i++;
	}
	ft_printf("\n");
}

//!REMOVE
void	output(t_stack *a, t_stack *b)
{
	if (a)
	{
		ft_printf("\n---------------------A---------------------\n");
		print_stack(a);
		ft_printf("\n");
	}
	if (b)
	{
		ft_printf("\n---------------------B---------------------\n");
		print_stack(b);
		ft_printf("\n");
	}
}

bool	is_stack_valid(t_stack *stack)
{
	return (stack && stack->elems);
}

void ft_put_error()
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	free_argv(char *argv[])
{
	int	i = 0;

	while (argv[i] != NULL)
		free(argv[i++]);
	free(argv);
}

void	free_stack(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack->elems)
	{
		while (i < stack->act_size && (stack->elems)[i] != NULL)
		{
			free((stack->elems)[i]);
			i++;
		}
		free(stack->elems);
	}
	free(stack);
}

void	free_all(char *argv[], t_stack *a, t_stack *b)
{
	if (argv)
		free_argv(argv);
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
}
