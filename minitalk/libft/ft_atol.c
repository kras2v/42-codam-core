/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:28:01 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/06 22:43:45 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

static int	ft_is_plus_or_minus(char c)
{
	return (c == '-' || c == '+');
}

static void	ft_calc_sign_and_move(const char **nptr, int *sign)
{
	if (**nptr == '-')
		*sign = -1;
	else
		*sign = 1;
	(*nptr)++;
}

static long long	ft_str_to_num_converter(const char *nptr)
{
	long long	res;

	res = 0;
	while (ft_isdigit(*nptr))
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return (res);
}

long	ft_atol(const char *nptr)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (ft_is_plus_or_minus(*nptr))
		ft_calc_sign_and_move(&nptr, &sign);
	res = ft_str_to_num_converter(nptr);
	return (res *= sign);
}
