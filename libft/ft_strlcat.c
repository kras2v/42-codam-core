/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:30:20 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/08 17:28:31 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		dst_len;
	size_t		src_len;

	i = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (src_len + size);
	while (src[i] != '\0' && i < size - dst_len - 1)
	{
		dst[i + dst_len] = src[i];
		i++;
	}
	dst[i + dst_len] = '\0';
	return (dst_len + src_len);
}

/* #include <stdio.h>
#include <string.h>
int	main(void)
{
	char dest[15] = "";
	char src[6] = "hell";

	printf("%ld\n", ft_strlcat(dest, src, 0));
	printf("%s\n", dest);

	char dest1[6]= "";
	char src1[6] = "hell";

	printf("%d\n", strlcat(dest1, src1, 0));
	printf("%s\n", dest1);
} */
