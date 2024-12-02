/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instructions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:00:02 by kvalerii          #+#    #+#             */
/*   Updated: 2024/11/29 11:21:45 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

static int	is_stack_valid(t_stack *stack)
{
	return (stack && stack->values);
}

static int	has_min_elems(t_stack *stack, int min_size)
{
	return (stack->act_size >= min_size);
}

static int	is_possible_swap_or_rotate(t_stack *stack)
{
	return (is_stack_valid(stack) && has_min_elems(stack, 2));
}

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	rotate(t_stack *stack)
{
	int	first;
	int	old_index;
	int	new_index;

	old_index = 0;
	first = *(stack->values[old_index]);
	while (old_index < stack->act_size - 1)
	{
		new_index = old_index + 1;
		*(stack->values[old_index]) = *(stack->values[new_index]);
		old_index++;
	}
	*(stack->values[stack->act_size - 1]) = first;
}

static void	rev_rotate(t_stack *stack)
{
	int	last;
	int	old_index;
	int	new_index;

	old_index = stack->act_size - 1;
	last = *(stack->values[old_index]);
	while (old_index > 0)
	{
		new_index = old_index - 1;
		*(stack->values[old_index]) = *(stack->values[new_index]);
		old_index--;
	}
	*(stack->values[0]) = last;
}

//(swap a): Swap the first 2 elements at the top of stack a.
void	sa(t_stack *a)
{
	if (!is_possible_swap_or_rotate(a))
		return ;
	swap(a->values[0], a->values[1]);
	ft_printf("sa\n");
}

//(swap b): Swap the first 2 elements at the top of stack b.
void	sb(t_stack *b)
{
	if (!is_possible_swap_or_rotate(b))
		return ;
	swap(b->values[0], b->values[1]);
	ft_printf("sb\n");
}

//sa and sb at the same time.
void	ss(t_stack *a, t_stack *b)
{
	int	is_a_valid;
	int	is_b_valid;
	
	is_a_valid = is_possible_swap_or_rotate(a);
	is_b_valid = is_possible_swap_or_rotate(b);
	if (is_a_valid)
		swap(a->values[0], a->values[1]);
	if (is_b_valid)
		swap(b->values[0], b->values[1]);
	if (is_a_valid || is_b_valid)
	ft_printf("ss\n");
}

//(rotate a): Shift up all elements of stack a by 1.
void	ra(t_stack *a)
{
	if (!is_possible_swap_or_rotate(a))
		return ;
	rotate(a);
	ft_printf("ra\n");
}

//(rotate b): Shift up all elements of stack b by 1.
void	rb(t_stack *b)
{
	if (!is_possible_swap_or_rotate(b))
		return ;
	rotate(b);
	ft_printf("rb\n");
}

//ra and rb at the same time.
void	rr(t_stack *a, t_stack *b)
{
	int	is_a_valid;
	int	is_b_valid;
	
	is_a_valid = is_possible_swap_or_rotate(a);
	is_b_valid = is_possible_swap_or_rotate(b);
	if (is_a_valid)
		rotate(a);
	if (is_b_valid)
		rotate(b);
	if (is_a_valid || is_b_valid)
	ft_printf("rr\n");
}

//rra (reverse rotate a): Shift down all elements of stack a by 1
void	rra(t_stack *a)
{
	if (!is_possible_swap_or_rotate(a))
		return ;
	rev_rotate(a);
	ft_printf("rra\n");
}

//rrb (reverse rotate b): Shift down all elements of stack b by 1
void	rrb(t_stack *b)
{
	if (!is_possible_swap_or_rotate(b))
		return ;
	rev_rotate(b);
	ft_printf("rrb\n");
}

//rrr : rra and rrb at the same time
void	rrr(t_stack *a, t_stack *b)
{
	int	is_a_valid;
	int	is_b_valid;
	
	is_a_valid = is_possible_swap_or_rotate(a);
	is_b_valid = is_possible_swap_or_rotate(b);
	if (is_a_valid)
		rev_rotate(a);
	if (is_b_valid)
		rev_rotate(b);
	if (is_a_valid || is_b_valid)
	ft_printf("rrr\n");
}

void	pa(t_stack *a, t_stack *b)
{
	int	i;

	if (!is_stack_valid(a) ||
		!is_stack_valid(b) ||
		!has_min_elems(b, 1))
				return ;
	i = 0;
	while (a->values[i] != NULL)
		i++;
	a->values[i] = malloc(sizeof(int));
	if (!a->values[i])
	{	
		free_all(NULL, a, b);
		ft_putstr_fd("Error\n", 2);
		return ;
	}
	a->act_size++;
	rev_rotate(a);
	*(a->values[0]) = *(b->values[0]);
	rotate(b);
	free(b->values[b->act_size - 1]);
	b->values[b->act_size - 1] = NULL;
	b->act_size--;
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	int	i;

	if (!is_stack_valid(a) ||
		!is_stack_valid(b) ||
		!has_min_elems(a, 1))
				return ;
	i = 0;
	while (b->values[i] != NULL)
		i++;
	b->values[i] = malloc(sizeof(int));
	if (!b->values[i])
	{	
		free_all(NULL, a, b);
		ft_putstr_fd("Error\n", 2);
		return ;
	}
	b->act_size++;
	rev_rotate(b);
	*(b->values[0]) = *(a->values[0]);
	rotate(a);
	free(a->values[a->act_size - 1]);
	a->values[a->act_size - 1] = NULL;
	a->act_size--;
	ft_printf("pb\n");
}
