/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:22:12 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/09 23:38:51 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p_s;

	p_s = (char *)s + ft_strlen(s);
	while (p_s != s)
	{
		if (*p_s == c)
			return (p_s);
		p_s--;
	}
	if (*p_s == c)
		return (p_s);
	return (0);
}

/* #include <string.h>
#include <stdio.h>
int	main()
{
	 // Test case 1: Basic test
	const char *test_str1 = "Hello, World!";
	char test_char1 = 'W';
	char *expected1 = strrchr(test_str1, test_char1);
	char *actual1 = ft_strrchr(test_str1, test_char1);
	printf("Test 1 - Basic test:\n");
	printf("Expected: %s\n", expected1);
	printf("Actual: %s\n\n", actual1);

	// Test case 2: Character not found
	const char *test_str2 = "Hello, World!";
	char test_char2 = 'x';
	char *expected2 = strrchr(test_str2, test_char2);
	char *actual2 = ft_strrchr(test_str2, test_char2);
	printf("Test 2 - Character not found:\n");
	printf("Expected: %s\n", expected2);
	printf("Actual: %s\n\n", actual2);

	// Test case 3: Find null terminator
	const char *test_str3 = "Hello, World!";
	char test_char3 = '\0';
	char *expected3 = strrchr(test_str3, test_char3);
	char *actual3 = ft_strrchr(test_str3, test_char3);
	printf("Test 3 - Find null terminator:\n");
	printf("Expected: %s\n", expected3);
	printf("Actual: %s\n\n", actual3);

	// Test case 4: Find last occurence character if many
	const char *test_str4 = "Hello, World, Hello!";
	char test_char4 = 'H';
	char *expected4 = strrchr(test_str4, test_char4);
	char *actual4 = ft_strrchr(test_str4, test_char4);
	printf("Test 4 - Find last character:\n");
	printf("Expected: %s\n", expected4);
	printf("Actual: %s\n\n", actual4);

	// Test case 5: Find last character
	const char *test_str5 = "Hello, World!";
	char test_char5 = '!';
	char *expected5 = strrchr(test_str5, test_char5);
	char *actual5 = ft_strrchr(test_str5, test_char5);
	printf("Test 5 - Find last character:\n");
	printf("Expected: %s\n", expected5);
	printf("Actual: %s\n\n", actual5);
}
 */