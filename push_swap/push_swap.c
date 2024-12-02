/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:53:42 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/02 18:02:35 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

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

int	ft_sort(t_stack *a, t_stack *b)
{
	int pivot_index;
	int i, j;

	pivot_index = (int)a->act_size / 2;
	
}

// int	main(int argc, char **argv)
// {
// 	t_stack	*a = list_creator(argc, argv);
// 	if (!a)
// 		return (ft_putstr_fd("Error\n", 2), 1);
// 	t_stack	*b = create_stack(a->max_size);
// 	output(a, b);
// 	ft_sort(a, b);
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
	argv[0] = ft_strdup("push_swap");
	argv[1] = ft_strdup("2 1 3 6 5 8");
	argv[2] = NULL;
	t_stack	*a = list_creator(argc, argv);
	if (!a)
		return (ft_putstr_fd("Error\n", 2), 1);
	t_stack	*b = create_stack(a->max_size);
	if (!b)
		return (free_all(NULL, a, NULL), ft_putstr_fd("Error\n", 2), 1);
	output(a, b);
	ft_sort(a, b);
	output(a, b);
	free_stack(a);
	free_stack(b);
	free_argv(argv);
	return (0);
}
