/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:37:58 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/06 13:53:18 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/parser_utils.h"

static void	add_new_element(t_stack *a_stack, int i, long temp)
{
	a_stack->elems[i]->value = temp;
	a_stack->elems[i]->target = NULL;
	a_stack->act_size++;
}

static t_stack	*parse_multy_str(int argc, char **argv)
{
	int		i;
	long	temp;
	t_stack	*a_stack;

	i = 0;
	if (argc == 0)
		return (NULL);
	a_stack = allocate_stack(argc);
	if (!a_stack)
		return (NULL);
	while (i < a_stack->max_size && argv[i] != NULL)
	{
		if (!is_argv_i_valid(argv[i]))
			return (free_stack(a_stack), NULL);
		temp = ft_atol(argv[i]);
		if (is_elem_in_array(temp, a_stack->elems, i))
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
		ft_put_error();
	while (argv[argc] != NULL)
		argc++;
	a_stack = parse_multy_str(argc, argv);
	free_argv(argv);
	return (a_stack);
}

t_stack	*allocate_stack(int size)
{
	t_stack		*stack;
	int			i;

	stack = malloc(sizeof(t_stack));
	if (!stack || size == 0)
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

t_stack	*a_stack_creator(int argc, char **argv)
{
	if (argc == 2)
		return (parse_one_str(argv[1]));
	else
		return (parse_multy_str(--argc, ++argv));
	return (NULL);
}
