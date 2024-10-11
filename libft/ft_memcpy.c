/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:31:18 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/11 13:09:11 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*p_dest;
	unsigned char	*p_src;

	if (!dest && !src)
		return (NULL);
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
	char *dest = NULL;
	char *src = NULL;

	ft_memcpy(dest, src, 5);
	printf("%s\n", dest);

	char *dest1 = NULL;
	char *src1 = NULL;

	memcpy(dest1, src1, 5);
	printf("%s\n", dest1);
}
 */