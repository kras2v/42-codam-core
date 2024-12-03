/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:53:42 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/03 15:15:27 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/push_swap.h"

int	ft_find_max(t_stack *a)
{
	int	i;
	int	max;

	max = *(a->values[0]);
	i = 0;
	while (i < a->act_size)
	{
		if (*(a->values[i]) > max)
			max = *(a->values[i]);
		i++;
	}
	return (max);
}

void ft_sort_three(t_stack *a)
{
	int	max;

	max = ft_find_max(a);
	if (*(a->values[0]) == max)
		ra(a);
	else if(*(a->values[1]) == max)
		rra(a);
	if(*(a->values[0]) > *(a->values[1]))
		sa(a);
}

int	ft_is_sorted(t_stack *a)
{
	int	i;

	if (!a || !a->values)
		return 0;
	i = 0;
	while (a->act_size > 1 && i < a->act_size - 1)
	{
		if (*(a->values[i]) < *(a->values[i + 1]))
			i++;
		else 
			break;
	}
	return ((i + 1) == a->act_size);
}

int	main(int argc, char **argv)
{
	if (argc <= 1 || (argc == 2 && !argv[1][0]))
		return (1);
	t_stack	*a = list_creator(argc, argv);
	if (!a)
		ft_put_error();
	t_stack	*b = create_stack(a->max_size);
	if (!ft_is_sorted(a))
	{
		if (argc == 4)
			ft_sort_three(a);
	}
	output(a, b);
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
// 	int argc = 3;
// 	char **argv = malloc(4 * sizeof(char *));
// 	argv[0] = ft_strdup("push_swap");
// 	argv[1] = ft_strdup("-50");
// 	argv[2] = ft_strdup("-");
// 	argv[4] = NULL;
// 	t_stack	*a = list_creator(argc, argv);
// 	free_argv(argv);
// 	if (!a)
// 		ft_put_error();
// 	t_stack	*b = create_stack(a->max_size);
// 	output(a, b);
// 	//ft_sort(a, b);
// 	output(a, b);
// 	free_stack(a);
// 	free_stack(b);
// 	return (0);
// }

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