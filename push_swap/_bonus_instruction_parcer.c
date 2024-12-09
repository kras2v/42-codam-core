/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus_instruction_parcer.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:06:08 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/09 19:02:25 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_bonus_checker.h"

static t_bool	ft_execute_instruction(char **inst, size_t num,
								t_stack *a, t_stack *b)
{
	if (ft_strcmp(inst[num], "sa") == 0)
		sa(a);
	else if (ft_strcmp(inst[num], "sb") == 0)
		sb(b);
	else if (ft_strcmp(inst[num], "ss") == 0)
		ss(a, b);
	else if (ft_strcmp(inst[num], "pa") == 0)
		pa(a, b);
	else if (ft_strcmp(inst[num], "pb") == 0)
		pb(a, b);
	else if (ft_strcmp(inst[num], "ra") == 0)
		ra(a);
	else if (ft_strcmp(inst[num], "rb") == 0)
		rb(b);
	else if (ft_strcmp(inst[num], "rr") == 0)
		rr(a, b);
	else if (ft_strcmp(inst[num], "rra") == 0)
		rra(a);
	else if (ft_strcmp(inst[num], "rrb") == 0)
		rrb(b);
	else if (ft_strcmp(inst[num], "rrr") == 0)
		rrr(a, b);
	else
		return (free_all(inst, a, b), ft_put_error(), FALSE);
	return (TRUE);
}

static t_bool	ft_is_amount_of_new_lines_valid(char *line, char **instructions)
{
	size_t	count;
	size_t	amount_of_instructions;
	size_t	i;

	count = 0;
	i = 0;
	amount_of_instructions = 0;
	while (instructions[amount_of_instructions] != NULL)
		amount_of_instructions++;
	while (line[i])
	{
		if (line[i] == '\n')
			count++;
		i++;
	}
	return (count == amount_of_instructions);
}

static t_bool	ft_is_sorted(t_stack *a)
{
	int	i;

	if (!is_stack_valid(a))
		return (FALSE);
	i = 0;
	while (a->act_size > 1 && i < a->act_size - 1)
	{
		if ((a->elems[i])->value < (a->elems[i + 1])->value)
			i++;
		else
			break ;
	}
	return ((i + 1) == a->act_size);
}

static void	ft_show_result(char **instructions, t_stack *a, t_stack *b)
{
	if (ft_is_sorted(a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_all(instructions, a, b);
}

void	proceed_instructions(t_stack *a, t_stack *b)
{
	size_t	i;
	char	**instructions;
	char	*line;

	line = read_until_end(0);
	if (!line)
	{
		free_all(NULL, a, b);
		ft_put_error();
	}
	instructions = ft_split(line, '\n');
	if (!instructions || !ft_is_amount_of_new_lines_valid(line, instructions))
	{
		free(line);
		free_all(instructions, a, b);
		ft_put_error();
	}
	free(line);
	i = 0;
	while (instructions[i] != NULL)
	{
		ft_execute_instruction(instructions, i, a, b);
		i++;
	}
	ft_show_result(instructions, a, b);
}
