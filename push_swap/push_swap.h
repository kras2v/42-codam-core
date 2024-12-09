/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:52:15 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/09 22:19:39 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_boolean.h"
# include <limits.h>

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

void	ft_push_swap(t_stack *a, t_stack *b, int argc);

t_bool	is_stack_valid(t_stack *stack);
void	ft_put_error_and_free(t_stack *a, t_stack *b);
void	free_stack(t_stack *stack);
void	free_argv(char *argv[]);
void	free_all_stacks(t_stack *a, t_stack *b);

void	ft_refresh_stack_values(t_stack *stack);
void	ft_initialize_stacks(t_stack *a, t_stack *b);

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

t_bool	ft_is_value_in_stack(t_stack *a, int value);
void	ft_add_new_element(t_stack *a_stack, int i, long temp);
t_bool	ft_is_argv_i_valid(char *argv);
void	ft_genarate_stacks(t_stack **a, t_stack **b, int argc, char **argv);

t_bool	ft_is_sorted(t_stack *a);
t_elem	*ft_find_smallest_element(t_stack *stack);
void	ft_rotate_one_until_closest_on_top(t_stack *stack,
			t_elem *element, char stack_name);
void	ft_move_element_to_target(t_stack *a, t_stack *b);
void	ft_sort_three(t_stack *a);

#endif