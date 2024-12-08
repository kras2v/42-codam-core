/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:52:15 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/06 22:46:48 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/printf/ft_printf.h"
# include "libft/libft.h"
# include <limits.h>
# include "ft_boolean.h"

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

void	push_swap(t_stack *a, t_stack *b, int argc);

//instructions
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
//instructions utils
t_bool	has_min_amount_of_elems(t_stack *stack, int min_size);
t_bool	is_possible_swap_or_rotate(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	swap(int *a, int *b);

//stack utils
void	free_argv(char *argv[]);
void	free_stack(t_stack *stack);
void	free_all_stacks(t_stack *a, t_stack *b);
t_bool	is_stack_valid(t_stack *stack);
void	ft_put_error(void);

//parser utils
void	genarate_stacks(t_stack **a, t_stack **b, int argc, char **argv);
void	add_new_element(t_stack *a_stack, int i, long temp);

void	init_stacks(t_stack *a, t_stack *b);
void	update_stack_values(t_stack *stack);

//triple sort
t_elem	*find_smallest_element(t_stack *stack);
void	ft_sort_three(t_stack *a);

//sort
void	move_from_b_to_a(t_stack *a, t_stack *b);
void	rotate_until_element_on_top(t_stack *stack,
			t_elem *element, char stack_name);
t_bool	is_elem_in_array(int elem, t_elem **elems, int index);
t_bool	is_argv_i_valid(char *argv);

//!REMOVE PRINT
void	print_stack(t_stack *stack);
void	output(t_stack *a, t_stack *b);

#endif