/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus_checker.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 17:29:21 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/09 22:11:57 by valeriia         ###   ########.fr       */
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
	int				distance_to_target;
	int				position;
	t_bool			above_middle;
	t_bool			closest;
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

char	*read_until_end_of_file(int fd);

t_bool	ft_is_value_in_stack(t_stack *a, int value);
void	ft_add_new_element(t_stack *a_stack, int i, long temp);
t_bool	ft_is_argv_i_valid(char **argv, int i);
void	ft_genarate_stacks(t_stack **a, t_stack **b, int argc, char **argv);

t_bool	is_stack_valid(t_stack *stack);
void	ft_put_error(void);
void	free_argv(char *argv[]);
void	free_stack(t_stack *stack);
void	free_all(char **instructions, t_stack *a, t_stack *b);

void	ft_proceed_instructions(t_stack *a, t_stack *b);

t_bool	ft_has_min_amount_of_elems(t_stack *stack, int min_size);
t_bool	ft_is_possible_swap_or_rotate(t_stack *stack);
void	ft_rotate(t_stack *stack);
void	ft_swap(int *a, int *b);
void	ft_reverse_rotate(t_stack *stack);

void	ft_pa(t_stack *a, t_stack *b);
void	ft_pb(t_stack *a, t_stack *b);
void	ft_sa(t_stack *a);
void	ft_sb(t_stack *b);
void	ft_ss(t_stack *a, t_stack *b);
void	ft_ra(t_stack *a);
void	ft_rb(t_stack *b);
void	ft_rr(t_stack *a, t_stack *b);
void	ft_rra(t_stack *a);
void	ft_rrb(t_stack *b);
void	ft_rrr(t_stack *a, t_stack *b);

#endif