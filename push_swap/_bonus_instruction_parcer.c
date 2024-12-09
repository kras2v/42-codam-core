/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus_instruction_parcer.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:06:08 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/09 23:03:24 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_bonus_checker.h"

static t_bool	ft_execute_instruction(char **inst, size_t num,
								t_stack *a, t_stack *b)
{
	if (ft_strcmp(inst[num], "sa") == 0)
		ft_sa(a);
	else if (ft_strcmp(inst[num], "sb") == 0)
		ft_sb(b);
	else if (ft_strcmp(inst[num], "ss") == 0)
		ft_ss(a, b);
	else if (ft_strcmp(inst[num], "pa") == 0)
		ft_pa(a, b);
	else if (ft_strcmp(inst[num], "pb") == 0)
		ft_pb(a, b);
	else if (ft_strcmp(inst[num], "ra") == 0)
		ft_ra(a);
	else if (ft_strcmp(inst[num], "rb") == 0)
		ft_rb(b);
	else if (ft_strcmp(inst[num], "rr") == 0)
		ft_rr(a, b);
	else if (ft_strcmp(inst[num], "rra") == 0)
		ft_rra(a);
	else if (ft_strcmp(inst[num], "rrb") == 0)
		ft_rrb(b);
	else if (ft_strcmp(inst[num], "rrr") == 0)
		ft_rrr(a, b);
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
	if (is_stack_valid(a))
	{
		if (ft_is_sorted(a) && b->act_size == 0)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		free_all(instructions, a, b);
	}
}

void	ft_proceed_instructions(t_stack *a, t_stack *b)
{
	size_t	i;
	char	**instructions;
	char	*line;

	line = read_until_end_of_file(0);
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
