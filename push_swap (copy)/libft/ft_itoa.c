/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:45:07 by valeriia          #+#    #+#             */
/*   Updated: 2024/10/19 11:13:26 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_calc_num_len(size_t n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	ft_handle_sign(long *lnum, int n)
{
	*lnum = n;
	if (n < 0)
		(*lnum) = -(*lnum);
	return (n < 0);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		num_len;
	int		sign;
	long	lnum;

	sign = ft_handle_sign(&lnum, n);
	num_len = ft_calc_num_len(lnum);
	res = (char *)malloc((num_len + sign + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (sign)
		res[0] = '-';
	res[num_len + sign] = '\0';
	while (num_len-- > 0)
	{
		res[num_len + sign] = lnum % 10 + '0';
		lnum /= 10;
	}
	return (res);
}
