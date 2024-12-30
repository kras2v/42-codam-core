/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 12:05:20 by valeriia          #+#    #+#             */
/*   Updated: 2024/12/27 12:58:32 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>

static int put_int_part(double num)
{
	char	*int_part;
	int		int_part_num;
	int		len;

	int_part_num = (int)num;
	if (num < 0.0 && int_part_num == 0)
		ft_printf("-");
	int_part = ft_itoa(int_part_num);
	if (!int_part)
		return (0);
	ft_putstr_fd(int_part, 1);
	len = ft_strlen(int_part);
	free(int_part);
	return (len);
}

static int put_decimal_part(double num)
{
	double	decimal_part_num;
	double	decimal_part_num_after_multiply;
	int		i;

	if (num < 0.0)
		num = -num;
	decimal_part_num = num - ((int)num);
	i = 0;
	while (i < 6)
	{
		decimal_part_num_after_multiply = decimal_part_num * 10;
		ft_putnbr_fd((int)decimal_part_num_after_multiply, 1);
		decimal_part_num = (double)(decimal_part_num_after_multiply - (int)decimal_part_num_after_multiply);
		i++;
	}
	return (6);
}

int	ft_printf_f(double num)
{
	int		res;

	res = put_int_part(num);
	res += ft_printf_c('.');
	res += put_decimal_part(num);
	return (res);
}