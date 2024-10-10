/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:16:26 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/10 17:18:37 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/* #include <stdio.h>
#include <string.h>
int	main(void)
{
	char	s1[6] = "hello";
	printf("BEFORE ft_bzero with chars:\t %s\n", s1);
	ft_bzero(s1, sizeof(s1));
	s1[5] = '\0';
	printf("AFTER ft_bzero with chars:\t %s\n", s1);

	char	s2[6] = "hello";
	printf("\nBEFORE bzero with chars:\t %s\n", s2);
	bzero(s2, sizeof(s2));
	s2[5] = '\0';
	printf("AFTER bzero with chars:\t %s\n", s2);

	printf("\n________________________\n\n");
	int	i;
	
	int	i1[5] = {1, 1, 1, 1, 1};
	printf("BEFORE ft_bzero with ints:\t ");
	i = 0;
	while(i < 5)
		printf("%d ", i1[i++]);
	printf("\n");
	
	ft_bzero(i1, sizeof(i1));
	i = 0;
	printf("AFTER ft_bzero with ints:\t ");
	while(i < 5)
		printf("%d ", i1[i++]);
	printf("\n\n");

	int	i2[5] = {1, 1, 1, 1, 1};
	printf("BEFORE bzero with ints: \t ");
	i = 0;
	while(i < 5)
		printf("%d ", i2[i++]);
	printf("\n");
	
	ft_bzero(i2, sizeof(i2));
	i = 0;
	printf("AFTER bzero with ints:  \t ");
	while(i < 5)
		printf("%d ", i2[i++]);
	printf("\n");
} */