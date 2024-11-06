/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:16:08 by kvalerii          #+#    #+#             */
/*   Updated: 2024/11/06 14:11:47 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strndup(char *str, size_t size)
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

size_t	ft_strlen(char *s)
{
	size_t	index;

	index = 0;
	while (s[index] != '\0')
	{
		index++;
	}
	return (index);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	index;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = malloc(s1_len + s2_len + 1);
	if (!res)
		return (NULL);
	index = 0;
	while (s1[index] != '\0')
	{
		res[index] = s1[index];
		index++;
	}
	while (s2[index - s1_len] != '\0')
	{
		res[index] = s2[index - s1_len];
		index++;
	}
	res[index] = '\0';
	return (res);
}

int	ft_any(t_stash *stash, int c)
{
	size_t	index;

	index = 0;
	while (stash->stash[index] != '\0')
	{
		if ((stash->stash[index]) == c)
		{
			stash->contains_new_line = 1;
			stash->new_line_index = index;
			return (1);
		}
		index++;
	}
	stash->new_line_index = 0;
	return (0);
}
