/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:29:41 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/10 11:14:49 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	match;

	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	while (*big && len-- > 0)
	{
		match = 0;
		while (*big == little[match] && len-- > 0)
		{
			big++;
			match++;
			if (match == little_len)
				return ((char *)big - little_len);
		}
		big -= match;
		len += match;
		big++;
	}
	return (NULL);
}

/* #include <stdio.h>
#include <string.h>
int main() {
	char *big1 = "f";
	char *little = NULL;
	char *expected1 = ft_strnstr(big1, little, 0);
	printf("%s", expected1);
	return 0;
} */