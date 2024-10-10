/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:29:41 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/09 23:51:59 by valeriia         ###   ########.fr       */
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
		big++;
	}
	return (0);
}

/* #include <stdio.h>
#include <string.h>
int main() {
	// Test Case 1: Basic test with a match
	char big1[] = "lorem ipsum dolor sit amet";
	char little1[] = "dolor";
	char *expected1 = ft_strnstr(big1, little1, 15);
	printf("%s", expected1);
	return 0;
} */