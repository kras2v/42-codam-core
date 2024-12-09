/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:37:58 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/09 18:57:26 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_bonus_checker.h"

static t_stack	*allocate_stack(int size)
{
	t_stack		*stack;
	int			i;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->max_size = size;
	stack->act_size = 0;
	stack->elems = malloc(stack->max_size * sizeof(t_elem *));
	if (!stack->elems)
		return (free_stack(stack), NULL);
	i = 0;
	while (i < stack->max_size)
	{
		stack->elems[i] = NULL;
		i++;
	}
	return (stack);
}

static t_stack	*parse_multy_str(int argc, char **argv)
{
	int		i;
	long	temp;
	t_stack	*a_stack;

	if (argc == 0)
		return (NULL);
	a_stack = allocate_stack(argc);
	if (!a_stack)
		return (NULL);
	i = 0;
	while (i < a_stack->max_size && argv[i] != NULL)
	{
		if (!is_argv_i_valid(argv[i]))
			return (free_stack(a_stack), NULL);
		temp = ft_atoi(argv[i]);
		if (is_value_in_stack(a_stack, temp))
			return (free_stack(a_stack), NULL);
		a_stack->elems[i] = malloc(sizeof(t_elem));
		if (!a_stack->elems[i])
			return (free_stack(a_stack), NULL);
		add_new_element(a_stack, i, temp);
		i++;
	}
	return (a_stack);
}

static t_stack	*parse_one_str(const char *str)
{
	char		**argv;
	int			argc;
	t_stack		*a_stack;

	argc = 0;
	argv = ft_split(str, ' ');
	if (!argv)
	{
		ft_put_error();
	}
	while (argv[argc] != NULL)
	{
		argc++;
	}
	a_stack = parse_multy_str(argc, argv);
	if (!a_stack)
	{
		free_argv(argv);
		ft_put_error();
	}
	free_argv(argv);
	return (a_stack);
}

static t_stack	*a_stack_creator(int argc, char **argv)
{
	if (argc == 2)
	{
		return (parse_one_str(argv[1]));
	}
	else
	{
		return (parse_multy_str(--argc, ++argv));
	}
	return (NULL);
}

void	genarate_stacks(t_stack **a, t_stack **b, int argc, char **argv)
{
	(*a) = a_stack_creator(argc, argv);
	if (!(*a))
	{
		ft_put_error();
	}
	(*b) = allocate_stack((*a)->max_size);
	if (!(*b))
	{
		free_all(NULL, (*a), NULL);
		ft_put_error();
	}
}
