/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:53:42 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/06 14:46:55 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int	main(int argc, char **argv)
{
	t_elem	*smallest;

	if (argc <= 1)
		return (1);
	t_stack	*a = a_stack_creator(argc, argv);
	if (!a)
		ft_put_error();
	t_stack	*b = allocate_stack(a->max_size);
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
			init_stacks(a, NULL);
			smallest = find_smallest_element(a);
			rotate_until_element_on_top(a, smallest, 'a');
		}
	}
	free_stack(a);
	free_stack(b);
	return (0);
}

// int	main(void)
// {
// // 	//?MULTY LINES
// // 	// int argc = 11;
// // 	// char **argv = malloc(12 * sizeof(char *));
// // 	// argv[0] = ft_strdup("push_swap");
// // 	// argv[1] = ft_strdup("1");
// // 	// argv[2] = ft_strdup("3");
// // 	// argv[3] = ft_strdup("5");
// // 	// argv[4] = ft_strdup("+9");
// // 	// argv[5] = ft_strdup("20");
// // 	// argv[6] = ft_strdup("-4");
// // 	// argv[7] = ft_strdup("50");
// // 	// argv[8] = ft_strdup("60");
// // 	// argv[9] = ft_strdup("04");
// // 	// argv[10] = ft_strdup("08");
// // 	// argv[11] = NULL;

// 	//?ONE STRING
// 	int argc = 2;
// 	char **argv = malloc(3 * sizeof(char *));
// 	t_elem	*smallest;
// 	argv[0] = ft_strdup("./push_swap");
// 	argv[1] = ft_strdup("");
// 	argv[2] = NULL;
// 	t_stack	*a = list_creator(argc, argv);
// 	free_argv(argv);
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
// 			while (a->act_size > 3)
// 				pb(a, b);
// 			ft_sort_three(a);
// 			output(a, b);
// 			while (b->act_size > 0)
// 			{
// 				init_stacks(a, b);
// 				output(a, b);
// 				move_from_b_to_a(a, b);
// 			}
// 			set_curent_position(a);
// 			smallest = find_smallest_element(a);
// 			//ft_printf("%d", smallest.value);
// 			rotate_until_element_on_top(a, smallest, 'a');
// 		}
// 	}
// 	output(a, b);
// 	free_stack(a);
// 	free_stack(b);
// 	return (0);
// }