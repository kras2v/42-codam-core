/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_validation_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:46:34 by kvalerii          #+#    #+#             */
/*   Updated: 2025/05/06 20:46:41 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	ft_isanum(char character)
{
	return (character >= '0' && character <= '9');
}

long	ft_atol(char *str)
{
	long	result;
	int		sign;
	size_t	i;

	sign = 1;
	result = 0;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] != '\0' && ft_isanum(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	ft_calculate_num_len(int number)
{
	size_t	len;
	size_t	l_number;

	len = 0;
	l_number = number;
	if (number == 0)
	{
		return (1);
	}
	if (number < 0)
	{
		len++;
		l_number *= -1;
	}
	while (l_number > 0)
	{
		l_number /= 10;
		len++;
	}
	return (len);
}
