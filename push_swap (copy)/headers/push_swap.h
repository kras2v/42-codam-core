/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:52:15 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/05 15:01:43 by kvalerii         ###   ########.fr       */
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

t_stack	*list_creator(int argc, char **argv);
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

void	free_argv(char *argv[]);
void	free_stack(t_stack *stack);
void	free_all(char *argv[], t_stack *a, t_stack *b);
int		is_stack_valid(t_stack *stack);
void	ft_put_error();

t_stack	*create_stack(int size);
t_stack	*list_creator(int argc, char **argv);

//sort
int		find_biggest_value(t_stack *stack);
t_elem	*find_smallest_element(t_elem *min, t_stack *stack);
void	ft_sort_three(t_stack *a);
int		ft_is_sorted(t_stack *a);
void	get_target_value(t_stack *a, t_stack *b);
void	set_curent_position(t_stack *stack);
void	init_stacks(t_stack *a, t_stack *b);
void	get_push_price(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *b);
void	move_from_b_to_a(t_stack *a, t_stack *b);
void	rotate_until_element_on_top(t_stack *stack, t_elem *element, char stack_name);

//!REMOVE PRINT
void	print_stack(t_stack *stack);
void	output(t_stack *a, t_stack *b);

#endif