/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 21:04:07 by valeriia          #+#    #+#             */
/*   Updated: 2024/10/30 10:55:01 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_handle_null(void)
{
	char	*res;

	res = "(nil)";
	ft_putstr_fd(res, 1);
	return (ft_strlen(res));
}

int	ft_printf_p(unsigned long dec)
{
	char	*base;

	if (!dec)
		return (ft_handle_null());
	base = "0123456789abcdef";
	ft_putstr_fd("0x", 1);
	return (2 + ft_convert_to_base(dec, base, ft_strlen(base)));
}
