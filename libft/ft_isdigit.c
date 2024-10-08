/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 10:31:34 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/08 12:19:07 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/* #include <stdio.h>
#include <ctype.h>
int	main(void)
{
	printf("%d\n", ft_isdigit(48));
	printf("%d\n", isdigit(48));
} */