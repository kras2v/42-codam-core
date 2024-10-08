/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:41:34 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/08 12:21:36 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/* #include <stdio.h>
#include <ctype.h>
int	main(void)
{
	printf("%d\n", ft_isascii(128));
	printf("%d\n", isascii(128));
} */