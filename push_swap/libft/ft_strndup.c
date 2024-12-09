/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:07:59 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/08 18:08:07 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t size)
{
	char	*res;
	size_t	index;

	res = malloc(size + 1);
	if (!res)
		return (NULL);
	index = 0;
	while (str[index] != '\0' && index < size)
	{
		res[index] = str[index];
		index++;
	}
	res[index] = '\0';
	return (res);
}
