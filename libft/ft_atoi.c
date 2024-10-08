/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:28:01 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/08 17:59:18 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	ft_atoi(const char *nptr)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		sign = 1 - 2 * (*nptr++ == '-');
	while (ft_isdigit(*nptr))
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return (res *= sign);
}

/* #include <stdio.h>
#include <string.h>
int	main(void)
{
	printf("%d\n", ft_atoi(" \n  -523555"));
	printf("%d\n", atoi(" \n  -523555"));
} */
