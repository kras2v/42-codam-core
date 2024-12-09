/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus_checker_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:52:13 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/09 22:45:25 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_bonus_checker.h"

t_bool	is_stack_valid(t_stack *stack)
{
	return (stack && stack->elems);
}

void	ft_put_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	free_argv(char *argv[])
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
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

void	free_all(char **instructions, t_stack *a, t_stack *b)
{
	if (instructions)
	{
		free_argv(instructions);
	}
	if (a)
	{
		free_stack(a);
	}
	if (b)
	{
		free_stack(b);
	}
}
