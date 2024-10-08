/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:21:45 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/08 17:26:54 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 && (*s1 == *s2) && --n > 0)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/* #include <stdio.h>
#include <string.h>
int	main(void)
{
	printf("%d\n", ft_strncmp("", "A", 0));
	printf("%d\n", strncmp("", "A", 0));
} */