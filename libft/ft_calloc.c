/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:41:42 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/18 14:50:05 by kvalerii         ###   ########.fr       */
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
		return ((void *)malloc(0));
	if (ft_is_overflow(nmemb, size))
		return (NULL);
	total_size = nmemb * size;
	arr = (char *)malloc((total_size) * sizeof(char));
	if (!arr)
		return (NULL);
	ft_bzero(arr, total_size);
	return ((void *)arr);
}
