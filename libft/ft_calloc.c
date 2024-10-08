/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:41:42 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/08 18:21:27 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*arr;
	size_t	i;

	i = 0;
	if(size == 0 || nmemb == 0 || nmemb > SIZE_MAX / size)
		return (0);
	arr = (char *)malloc(nmemb * size);
	if (!arr)
		return (0);
	while (i < nmemb * size)
	{
		arr[i] = 0;
		i++;
	}
	return (arr);
}

/* include <stdio.h>
int	main(void)
{
	int	*a;
	int	nmemb;
	int	i;

	nmemb = 18446744073709551615UL;
	a = ft_calloc(nmemb, sizeof(int));
	if(a == NULL)
		return (1);
	i = 0;
	while (i < 5)
		printf("%d", a[i++]);
	free(a);
	printf("\n");
	
	int *a1;
	a1 = calloc(nmemb, sizeof(int));
	if(a1 == NULL)
		return (1);
	i = 0;
	while(i < 5)
		printf("%d", a1[i++]);
	free(a1);
} */