/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:26:57 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/18 17:47:24 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	void	*p_s;

	p_s = s;
	while (n-- > 0)
	{
		*((unsigned char *)p_s) = (unsigned char)c;
		p_s++;
	}
	return (s);
}
