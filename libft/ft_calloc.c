/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:41:42 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/11 18:49:41 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_overflow(size_t nmemb, size_t size)
{
	return (nmemb > SIZE_MAX / size);
}

static int	ft_is_size_or_nmem_valid(size_t nmemb, size_t size)
{
	return (size == 0 || nmemb == 0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*arr;
	size_t	total_size;

	if (ft_is_size_or_nmem_valid(nmemb, size))
		return ((void *)malloc(1));
	if (ft_is_overflow(nmemb, size))
		return (NULL);
	total_size = nmemb * size;
	arr = (char *)malloc((total_size) * sizeof(char));
	if (!arr)
		return (NULL);
	ft_bzero(arr, total_size);
	return ((void *)arr);
}

/* #include <stdio.h>
int	main(void)
{
	int	*a;
	int	i;
	size_t nmemb = 18446744073709551615UL + 1;
	size_t size = 18446744073709551615UL; 

	a = ft_calloc(nmemb, size);
	// if(a == NULL)
	// 	return (1);
	i = 0;
	// while (i < 5)
	// 	printf("%d", a[i++]);
	free(a);
	printf("\n");
	
	// int *a1;
	// a1 = calloc(nmemb, sizeof(int));
	// if(a1 == NULL)
	// 	return (1);
	// i = 0;
	// while(i < 5)
	// 	printf("%d", a1[i++]);
	// free(a1);
} */