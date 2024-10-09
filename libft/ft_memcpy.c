/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:31:18 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/09 10:18:44 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*p_dest;
	unsigned char	*p_src;

	i = 0;
	p_dest = (unsigned char *)dest;
	p_src = (unsigned char *)src;
	while (i < n)
	{
		p_dest[i] = p_src[i];
		i++;
	}
	return (dest);
}

/* #include <stdio.h>
#include <string.h>
int	main(void)
{
	char dest[6] = "world";
	char src[6] = "hello";

	ft_memcpy(dest, src, 20);
	printf("%s\n", dest);

	char dest1[6] = "world";
	char src1[6] = "hello";

	memcpy(dest1, src1, 20);
	printf("%s\n", dest1);
} */
