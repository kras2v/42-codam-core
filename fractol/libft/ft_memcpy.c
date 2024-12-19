/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:31:18 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/18 17:49:17 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*p_dest;

	if (!dest && !src)
		return (NULL);
	p_dest = dest;
	while (n-- > 0)
	{
		(*(unsigned char *)p_dest) = *((unsigned char *)src);
		p_dest++;
		src++;
	}
	return (dest);
}
