/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:47:48 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/09 12:25:55 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*char_dest;
	char	*char_src;

	char_dest = (char *) dest;
	char_src = (char *) src;
	if (char_dest < char_src)
	{
		i = 0;
		while (i < n)
		{
			char_dest[i] = char_src[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i > 0)
		{
			i--;
			char_dest[i] = char_src[i];
		}
	}
	return (dest);
}

/* #include <stdio.h>
#include <string.h>
int	main(void)
{
	// 1. Basic non-overlapping memory regions
	char src1_exp[] = "Hello, World!";
	char dst1_exp[20];
	printf("1. Basic non-overlapping memory regions\n src: %s\n", src1_exp);
	memmove(dst1_exp, src1_exp, strlen(src1_exp) + 1);
	printf("Expected result: (memmove): %s\n", dst1_exp);
	
	char src1_act[] = "Hello, World!";
	char dst1_act[20];
	ft_memmove(dst1_act, src1_act, strlen(src1_act) + 1);
	printf("Actual result: (ft_memmove): %s\n\n", dst1_act);

	// 2. Overlapping regions (src before dest)
	char src2_exp[] = "Overlap test";
	printf("2. Overlapping regions (src before dest)\n");
	memmove(src2_exp + 4, src2_exp, 7);
	printf("Expected result: (memmove): %s\n", src2_exp);

	char src2_act[] = "Overlap test";
	ft_memmove(src2_act + 4, src2_act, 7);
	printf("Actual result: (ft_memmove): %s\n\n", src2_act);

	// 3. Overlapping regions (dest before src)
	char src3_exp[] = "1234567890";
	printf("3. Overlapping regions (dest before src)\n");
	memmove(src3_exp, src3_exp + 4, 6);
	printf("Expected result: (memmove): %s\n", src3_exp);

	char src3_act[] = "1234567890";
	ft_memmove(src3_act, src3_act + 4, 6);
	printf("Actual result: (ft_memmove): %s\n\n", src3_act);

	// 4. Zero-length copy
	char src4[] = "Hello, World!";
	char dst4_exp[20] = "Initial";
	printf("4. Zero-length copy\n src: %s\n", src1_exp);
	memmove(dst4_exp, src4, 0);
	printf("Expected result: (exp_memmove): %s\n", dst4_exp);
	
	char dst4_act[20] = "Initial"; 
	ft_memmove(dst4_act, src4, 0); 
	printf("Actual result: (memmove): %s\n\n", dst4_act);

	// 5. Copy to the same location (no change expected)
	char src5[] = "Same location";
	printf("5. Copy to the same location\n");
	memmove(src5, src5, strlen(src5) + 1);
	printf("Expected result: result (memmove): %s\n", src5); 
	
	ft_memmove(src5, src5, strlen(src5) + 1); 
	printf("Actual result: result (exp_memmove): %s\n\n", src5); 

	// 6. Copy to a smaller buffer (partial copy)
	char src6[] = "Partial copy";
	char dst6_exp[8];
	char dst6_act[8]; 
	printf("6. Copy to a smaller buffer (partial copy)\n");
	memmove(dst6_exp, src6, 7); 
	dst6_exp[7] = '\0';
	printf("Expected result: dst (memmove): %s\n", dst6_exp);

	ft_memmove(dst6_act, src6, 7);
	dst6_act[7] = '\0'; 
	printf("Actual result: dst (exp_memmove): %s\n\n", dst6_act);

	// 7. Backward copy (safe handling of overlapping memory)
	char src7_exp[] = "Backward test";
	printf("7. Backward copy (safe handling)\n");
	memmove(src7_exp + 4, src7_exp, 9);
	printf("Expected result: result (memmove): %s\n", src7_exp);
	
	char src7_act[] = "Backward test";
	ft_memmove(src7_act + 4, src7_act, 9);
	printf("Actual result: result (exp_memmove): %s\n", src7_act);
	
	return 0;
} */
