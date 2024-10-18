/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:22:12 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/18 17:32:01 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*p_s_end;
	unsigned char	*p_s_start;

	p_s_start = (unsigned char *)s;
	p_s_end = p_s_start + ft_strlen(s);
	while (p_s_start <= p_s_end)
	{
		if (*p_s_start == (unsigned char)c)
			return ((char *)p_s_start);
		p_s_start++;
	}
	return (0);
}
