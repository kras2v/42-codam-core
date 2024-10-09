/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:26:57 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/09 10:13:07 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/* #include <stdio.h>
#include <string.h>
int	main(void)
{
	char	s1[6] = "hello";
	printf("BEFORE ft_memset with chars:\t %s\n", s1);
	ft_memset(s1, '0', sizeof(s1));
	s1[5] = '\0';
	printf("AFTER ft_memset with chars:\t %s\n", s1);

	char	s2[6] = "hello";
	printf("\nBEFORE memset with chars:\t %s\n", s2);
	memset(s2,'0',sizeof(s2));
	s2[5] = '\0';
	printf("AFTER memset with chars:\t %s\n", s2);

	printf("\n________________________\n\n");
	int	i;
	
	int	i1[5] = {-1, -51, -4651, 155555555, 6661};
	printf("BEFORE ft_memset with ints:\t ");
	i = 0;
	while(i < 5)
		printf("%d ", i1[i++]);
	printf("\n");
	
	ft_memset(i1, 257, sizeof(i1));
	i = 0;
	printf("AFTER ft_memset with ints:\t ");
	while(i < 5)
		printf("%d ", i1[i++]);
	printf("\n\n");

	int	i2[5] = {-1, -51, -4651, 155555555, 6661};
	printf("BEFORE memset with ints: \t ");
	i = 0;
	while(i < 5)
		printf("%d ", i2[i++]);
	printf("\n");

	memset(i2, 1, sizeof(i2));
	i = 0;
	printf("AFTER memset with ints:  \t ");
	while(i < 5)
		printf("%d ", i2[i++]);
	printf("\n");
} */