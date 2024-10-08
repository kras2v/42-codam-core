/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:43:21 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/08 12:22:40 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

/* #include <stdio.h>
#include <ctype.h>
int	main(void)
{
	printf("%d\n", ft_isprint(32));
	printf("%d\n", isprint(32));
} */