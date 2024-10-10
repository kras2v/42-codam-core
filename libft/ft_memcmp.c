/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:15:18 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/10 11:19:39 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p_s1;
	unsigned char	*p_s2;

	if (n == 0)
		return (0);
	p_s1 = (unsigned char *)s1;
	p_s2 = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (*p_s1 != *p_s2)
			return (*p_s1 - *p_s2);
		p_s1++;
		p_s2++;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>

void print_result(const char *test_name, int expected, int actual)
{
    printf("%s:\n", test_name);
    printf("Expected: %d\n", expected);
    printf("Actual: %d\n\n", actual);
}

int	main()
{
    // Test case 1: Identical strings
    char str1[] = "Hello";
    char str2[] = "Hello";
    int expected1 = memcmp(str1, str2, 5);
    int actual1 = ft_memcmp(str1, str2, 5);
    print_result("Test 1 - Identical strings", expected1, actual1);

    // Test case 2: Different strings (first differing character)
    char str3[] = "Hello";
    char str4[] = "Helpo";
    int expected2 = memcmp(str3, str4, 5);
    int actual2 = ft_memcmp(str3, str4, 5);
    print_result("Test 2 - Different strings", expected2, actual2);

    // Test case 3: Different lengths, but same beginning
    char str5[] = "Hello";
    char str6[] = "Hell";
    int expected3 = memcmp(str5, str6, 5);  // Comparing up to 5 characters
    int actual3 = ft_memcmp(str5, str6, 5);
    print_result("Test 3 - Different lengths", expected3, actual3);

    // Test case 4: Empty strings
    char str7[] = "";
    char str8[] = "";
    int expected4 = memcmp(str7, str8, 0);
    int actual4 = ft_memcmp(str7, str8, 0);
    print_result("Test 4 - Empty strings", expected4, actual4);

    // Test case 5: Array of integers
    int int_arr1[] = {1, 2, 3, 4, 5};
    int int_arr2[] = {1, 2, 3, 4, 5};
    int expected5 = memcmp(int_arr1, int_arr2, sizeof(int_arr1));
    int actual5 = ft_memcmp(int_arr1, int_arr2, sizeof(int_arr1));
    print_result("Test 5 - Identical integer arrays", expected5, actual5);

    // Test case 6: Different integer arrays
    int int_arr3[] = {1, 2, 3, 4, 5};
    int int_arr4[] = {1, 2, 3, 4, 6};
    int expected6 = memcmp(int_arr3, int_arr4, sizeof(int_arr3));
    int actual6 = ft_memcmp(int_arr3, int_arr4, sizeof(int_arr3));
    print_result("Test 6 - Different integer arrays", expected6, actual6);

    return 0;
} */