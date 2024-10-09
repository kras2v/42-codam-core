/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:30:42 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/09 15:53:39 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p_s;

	p_s = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*p_s == (unsigned char)c)
			return ((void *)p_s);
		p_s++;
	}
	return (0);
}

/* #include <string.h>
#include <stdio.h>
int	main(void)
{
	// Test case 1: Basic test with character present
	const char *test_str1 = "Hello, World!";
	int test_char1 = 'l';
	void *expected1 = memchr(test_str1, test_char1, ft_strlen(test_str1));
	void *actual1 = ft_memchr(test_str1, test_char1, ft_strlen(test_str1));
	printf("Test 1 - Basic test (character present):\n");
	printf("Expected: %s\n", (char *)expected1);
	printf("Actual: %s\n\n", (char *)actual1);

	  // Test case 2: Character not present
	const char *test_str2 = "Hello, World!";
	int test_char2 = 'x';
	void *expected2 = memchr(test_str2, test_char2, ft_strlen(test_str2));
	void *actual2 = ft_memchr(test_str2, test_char2, ft_strlen(test_str2));
	printf("Test 2 - Character not found:\n");
	printf("Expected: %s\n", (char *)expected2);
	printf("Actual: %s\n\n", (char *)actual2);

	// Test case 3: Find null terminator within n
	const char *test_str3 = "Hello, World!";
	int test_char3 = '\0';
	void *expected3 = memchr(test_str3, test_char3, ft_strlen(test_str3) + 1);
	void *actual3 = ft_memchr(test_str3, test_char3, ft_strlen(test_str3) + 1);
	printf("Test 3 - Find null terminator:\n");
	printf("Expected: %s\n", (char *)expected3);
	printf("Actual: %s\n\n", (char *)actual3);

	// Test case 4: First character
	const char *test_str4 = "Hello, World!";
	int test_char4 = 'H';
	void *expected4 = memchr(test_str4, test_char4, ft_strlen(test_str4));
	void *actual4 = ft_memchr(test_str4, test_char4, ft_strlen(test_str4));
	printf("Test 4 - Find first character:\n");
	printf("Expected: %s\n", (char *)expected4);
	printf("Actual: %s\n\n", (char *)actual4);

	// Test case 5: Last character
	const char *test_str5 = "Hello, World!";
	int test_char5 = '!';
	void *expected5 = memchr(test_str5, test_char5, ft_strlen(test_str5));
	void *actual5 = ft_memchr(test_str5, test_char5, ft_strlen(test_str5));
	printf("Test 5 - Find last character:\n");
	printf("Expected: %s\n", (char *)expected5);
	printf("Actual: %s\n\n", (char *)actual5);

	// Test case 6: Search with n less than string length
	const char *test_str6 = "Hello, World!";
	int test_char6 = 'H';
	void *expected6 = memchr(test_str6, test_char6, 1);
	void *actual6 = ft_memchr(test_str6, test_char6, 1);
	printf("Test 6 - Search within limited length:\n");
	printf("Expected: %s\n", (char *)expected6);
	printf("Actual: %s\n\n", (char *)actual6);

	return 0;
} */