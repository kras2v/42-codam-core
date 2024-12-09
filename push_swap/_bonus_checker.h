/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus_checker.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:29:21 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/09 18:51:03 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _BONUS_CHECKER_H
# define _BONUS_CHECKER_H

# include "libft/libft.h"
# include <limits.h>

typedef enum s_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

typedef struct s_elem
{
	int				value;
	struct s_elem	*target;
	int				push_price;
	int				position;
	t_bool			above;
	t_bool			cheapest;
}	t_elem;

typedef struct s_stack
{
	t_elem	**elems;
	int		max_size;
	int		act_size;
}	t_stack;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*read_until_end(int fd);

t_bool	is_value_in_stack(t_stack *a, int value);
void	add_new_element(t_stack *a_stack, int i, long temp);
t_bool	is_argv_i_valid(char *argv);
void	genarate_stacks(t_stack **a, t_stack **b, int argc, char **argv);

t_bool	is_stack_valid(t_stack *stack);
void	ft_put_error(void);
void	free_argv(char *argv[]);
void	free_stack(t_stack *stack);
void	free_all(char **instructions, t_stack *a, t_stack *b);

void	proceed_instructions(t_stack *a, t_stack *b);

t_bool	has_min_amount_of_elems(t_stack *stack, int min_size);
t_bool	is_possible_swap_or_rotate(t_stack *stack);
void	rotate(t_stack *stack);
void	swap(int *a, int *b);
void	reverse_rotate(t_stack *stack);

void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

#endif