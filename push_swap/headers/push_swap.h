/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:52:15 by kvalerii          #+#    #+#             */
/*   Updated: 2024/11/28 18:36:13 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/printf/ft_printf.h"
# include "../libft/libft.h"
# include <limits.h>

typedef struct s_stack
{
	int	**values;
	int	max_size;
	int	act_size;
} t_stack;

t_stack	*list_creator(int argc, char **argv);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);

void	free_argv(char *argv[]);
void	free_stack(t_stack *stack);
void	free_all(char *argv[], t_stack *a, t_stack *b);

t_stack	*create_stack(int size);
t_stack	*list_creator(int argc, char **argv);

//!REMOVE PRINT
void	print_stack(t_stack *stack);
void	output(t_stack *a, t_stack *b);

#endif