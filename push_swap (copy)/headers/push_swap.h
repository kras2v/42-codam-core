/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:52:15 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/06 14:52:13 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/printf/ft_printf.h"
# include "../libft/libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_elem
{
	int				value;
	struct s_elem	*target;
	int				push_price;
	int				position;
	bool			above;
	bool			cheapest;
}	t_elem;

typedef struct s_stack
{
	t_elem	**elems;
	int		max_size;
	int		act_size;
} t_stack;

t_stack	*a_stack_creator(int argc, char **argv);
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

bool	has_min_amount_of_elems(t_stack *stack, int min_size);
bool	is_possible_swap_or_rotate(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	swap(int *a, int *b);

void	free_argv(char *argv[]);
void	free_stack(t_stack *stack);
void	free_all(char *argv[], t_stack *a, t_stack *b);
bool	is_stack_valid(t_stack *stack);
void	ft_put_error();

t_stack	*allocate_stack(int size);
t_stack	*a_stack_creator(int argc, char **argv);

//sort
t_elem	*find_smallest_element(t_stack *stack);
void	ft_sort_three(t_stack *a);
int		ft_is_sorted(t_stack *a);

void	init_stacks(t_stack *a, t_stack *b);
void	update_stack_values(t_stack *stack);

void	move_from_b_to_a(t_stack *a, t_stack *b);
void	rotate_until_element_on_top(t_stack *stack, t_elem *element, char stack_name);

//!REMOVE PRINT
void	print_stack(t_stack *stack);
void	output(t_stack *a, t_stack *b);

#endif