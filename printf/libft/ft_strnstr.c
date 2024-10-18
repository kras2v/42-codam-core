/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:29:41 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/18 17:04:46 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rollback(const char **big, size_t *len, size_t match)
{
	(*big) -= match;
	*len += match;
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	match;

	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	if (!big && len == 0)
		return (0);
	while (*big && len > 0)
	{
		match = 0;
		while (*big == little[match] && len-- > 0)
		{
			big++;
			match++;
			if (match == little_len)
				return ((char *)big - little_len);
		}
		ft_rollback(&big, &len, match);
		len--;
		big++;
	}
	return (NULL);
}
