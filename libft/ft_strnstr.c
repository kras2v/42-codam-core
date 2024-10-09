/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:29:41 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/09 15:53:09 by kvalerii         ###   ########.fr       */
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
		while (*big == little[match])
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
	char big1[] = "This is a simple test.";
	char little1[] = "simple";
	char *expected1 = ft_strnstr(big1, little1, strlen(big1));
	printf("%s", expected1);
	return 0;
} */