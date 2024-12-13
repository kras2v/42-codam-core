/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:59:16 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/18 16:36:29 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	lnum;

	lnum = n;
	if (n < 0)
	{
		lnum = -lnum;
		ft_putchar_fd('-', fd);
	}
	if (lnum >= 10)
		ft_putnbr_fd(lnum / 10, fd);
	ft_putchar_fd((lnum % 10 + '0'), fd);
}
