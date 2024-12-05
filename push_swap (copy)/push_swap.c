/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:53:42 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/05 15:03:05 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

void	print_stack_target(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->act_size && stack->elems[i] != NULL)
	{
		ft_printf("value    %d\t", (stack->elems[i])->value);
		ft_printf("target   %d\t", (stack->elems[i])->target->value);
		ft_printf("above    %d\t", (stack->elems[i])->target->above);
		ft_printf("position %d\t", (stack->elems[i])->position);
		ft_printf("tar_pos  %d\t", (stack->elems[i])->target->position);
		ft_printf("cheapest %d\t", (stack->elems[i])->cheapest);
		ft_printf("price    %d\n", (stack->elems[i])->push_price);
		i++;
	}
	ft_printf("\n");
}

// int	main(int argc, char **argv)
// {
// 	if (argc <= 1 || (argc == 2 && !argv[1][0]))
// 		return (1);
// 	t_stack	*a = list_creator(argc, argv);
// 	if (!a)
// 		ft_put_error();
// 	t_stack	*b = create_stack(a->max_size);
// 	if (!b)
// 		ft_put_error();
// 	if (!ft_is_sorted(a))
// 	{
// 		if (argc == 4)
// 			ft_sort_three(a);
// 		else
// 		{
// 			while (a->act_size-- > 3)
// 				pb(a, b);
// 			ft_sort_three(a);
// 			get_target_value(a, b);
// 			print_stack_target(b);
// 		}
// 	}
// 	output(a, b);
// 	free_stack(a);
// 	free_stack(b);
// 	return (0);
// }

int	main(void)
{
// 	//?MULTY LINES
// 	// int argc = 11;
// 	// char **argv = malloc(12 * sizeof(char *));
// 	// argv[0] = ft_strdup("push_swap");
// 	// argv[1] = ft_strdup("1");
// 	// argv[2] = ft_strdup("3");
// 	// argv[3] = ft_strdup("5");
// 	// argv[4] = ft_strdup("+9");
// 	// argv[5] = ft_strdup("20");
// 	// argv[6] = ft_strdup("-4");
// 	// argv[7] = ft_strdup("50");
// 	// argv[8] = ft_strdup("60");
// 	// argv[9] = ft_strdup("04");
// 	// argv[10] = ft_strdup("08");
// 	// argv[11] = NULL;

	//?ONE STRING
	int argc = 2;
	char **argv = malloc(3 * sizeof(char *));
	t_elem	smallest;
	argv[0] = ft_strdup("./push_swap");
	argv[1] = ft_strdup("10 77 -20 -8 -1 9 100 -48 -3 -21 -16 96");
	argv[2] = NULL;
	t_stack	*a = list_creator(argc, argv);
	free_argv(argv);
	if (!a)
		ft_put_error();
	t_stack	*b = create_stack(a->max_size);
	if (!b)
		ft_put_error();
	if (!ft_is_sorted(a))
	{
		if (argc == 4)
			ft_sort_three(a);
		else
		{
			while (a->act_size > 3)
				pb(a, b);
			ft_sort_three(a);
			while (b->act_size > 0)
			{
				init_stacks(a, b);
				move_from_b_to_a(a, b);
			}
			set_curent_position(a);
			find_smallest_element(&smallest, a);
			ft_printf("%d", smallest.value);
			//rotate_until_element_on_top(a, &smallest, 'a');
		}
	}
	output(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}

// void	ft_sort(t_stack *a, t_stack *b)
// {
// 	int	temp;
// 	int	rev_a;
// 	int j;

// 	if (a->act_size > 1 && *(a->values[0]) > *(a->values[1]))
// 		sa(a);
// 	pb(a, b);
// 	rev_a = 0;
// 	j = 0;
// 	while (a->act_size != 0)
// 	{
// 		// ft_printf("[%d]\n", j++);
// 		// output(a, b);
// 		if (a->act_size > 1 && *(a->values[0]) > *(a->values[1]))
// 			sa(a);
// 		temp = *(a->values[0]); //peek
// 		if (b->act_size != 0  && *(b->values[0]) > temp)
// 		{
// 			ra(a);
// 			while(b->act_size != 0 && *(b->values[0]) > temp)
// 			{
// 				pa(a, b);
// 			}
// 			rra(a);
// 		}
// 		pb(a, b);
// 	}
// 	int i;
// 	i = 0;
// 	int size = b->act_size;
// 	while (i < size)
// 	{
// 		pa(a, b);
// 		i++;
// 	}
// }