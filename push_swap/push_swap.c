/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:52:13 by kvalerii          #+#    #+#             */
/*   Updated: 2024/11/26 15:12:49 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(int argc, int *list)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		ft_printf("%d\n", list[i]);
		i++;
	}
}

int	ft_is_valid_sign(char c, int j)
{
	return ((j == 0 && c == '-') ||
			(j == 0 && c == '+'));
}

//!TO REMOVE ARGC FROM PARAMETRS JUST FOR PRINT
int	*parse_multy_str(int argc, char **argv)
{
	int		i;
	int		j;
	long	temp;
	int		*list;

	i = 0;
	list = malloc((argc) * sizeof(int));
	if (!list)
		return (NULL);
	while (i < argc && argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]) && !ft_is_valid_sign(argv[i][j], j))
			{
				ft_printf("%s", argv[i]);
				return (free(list), ft_putstr_fd("Error\n", 2), NULL);
			}
			j++;
		}
		if (j <= 11)
			temp = ft_atoi(argv[i]);
		if (temp > INT_MAX || temp < INT_MIN)
			return (free(list), ft_putstr_fd("Error\n", 2), NULL);
		list[i] = temp;
		i++;
	}
	print_list(argc, list);
	return (list);
}
//!TO REMOVE ARGC FROM PARAMETRS JUST FOR PRINT
int	*parse_one_str(const char *str)
{
	char	**argv;
	int		argc;
	int		*list;

	argc = 0;
	argv = ft_split(str, ' ');
	if (!argv)
		return (NULL);
	while (argv[argc] != NULL)
		argc++;
	list = parse_multy_str(argc, argv);
	argc = 0;
	while (argv[argc] != NULL)
		free(argv[argc++]);
	free(argv);
	return (list);
}

int	*list_creator(int argc, char **argv)
{
	if (argc <= 1)
		return (ft_putstr_fd("Error\n", 2), NULL);
	if (argc == 2)
		return (parse_one_str(argv[1]));
	else
		return (parse_multy_str(--argc, ++argv));
	return (NULL);
}

// int	main(void)
// {
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

// 	//?ONE STRING
// 	int argc = 2;
// 	char **argv = malloc(3 * sizeof(char *));
// 	argv[0] = ft_strdup("push_swap");
// 	argv[1] = ft_strdup("3 4 6 8 9 74 -56 +495");
// 	argv[2] = NULL;

// 	int	*list = list_creator(argc, argv);

// 	int	i = 0;
// 	while (argv[i] != NULL)
// 		free(argv[i++]);
// 	free(argv);

// 	if (!list)
// 		return (1);
// 	free(list);
// 	return (0);
// }

int	main(int argc, char **argv)
{
	int	*list = list_creator(argc, argv);

	if (!list)
		return (1);
	free(list);
	
	return (0);
}