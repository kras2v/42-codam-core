/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:47:23 by kvalerii          #+#    #+#             */
/*   Updated: 2024/11/28 17:12:13 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/parser_utils.h"

int	is_elem_in_array(int elem, int **array, int index)
{
	int	i;

	if (!array || !array[0] || !*(array[0]))
		return (0);
	i = 0;
	while (i < index)
	{
		if (elem ==  *(array[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_valid_sign(char c, int j)
{
	return ((j == 0 && c == '-') ||
			(j == 0 && c == '+'));
}

int	is_argv_i_valid(char *argv)
{
	int			j;

	j = 0;
	while (argv[j] != '\0')
	{
		if (!ft_isdigit(argv[j]) && !ft_is_valid_sign(argv[j], j))
			return (0);
		j++;
	}
	if (j > 11)
		return (0);
	return (1);
}