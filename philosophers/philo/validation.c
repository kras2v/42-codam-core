/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 18:46:49 by valeriia          #+#    #+#             */
/*   Updated: 2025/05/07 13:02:47 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static t_bool	is_overflow(long result)
{
	return ((result > INT_MAX) || (result < INT_MIN));
}

static t_bool	is_zero_invalid(long result, char *string)
{
	return ((result == 0 && !ft_isanum(string[0])));
}

long	ft_validate_number_input(char *string)
{
	int	result;

	result = ft_atol(string);
	if (ft_strlen(string) == ft_calculate_num_len(result))
	{
		if (is_overflow(result) || is_zero_invalid(result, string))
			return (NOTSET);
		return (result);
	}
	return (NOTSET);
}
