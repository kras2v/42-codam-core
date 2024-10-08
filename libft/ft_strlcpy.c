/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:30:20 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/08 17:05:11 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size <= 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

/* #include <stdio.h>
#include <string.h>
int	main(void)
{
	char dest[6] = "world";
	char src[6] = "hello";

	printf("%ld\n", ft_strlcpy(dest, src, 7));
	printf("%s\n", dest);

	char dest1[6]= "world";
	char src1[6] = "hello";

	printf("%d\n", strlcpy(dest1, src1, 7));
	printf("%s\n", dest1);
} */
