/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _bonus_proceed_standart_input.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:16:08 by kvalerii          #+#    #+#             */
/*   Updated: 2024/12/09 18:59:03 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_bonus_checker.h"

static char	*ft_join(char *stash, char *buffer)
{
	char	*res;

	res = ft_strjoin(stash, buffer);
	if (!res)
	{
		free(stash);
		return (NULL);
	}
	free(stash);
	return (res);
}

char	*read_until_end(int fd)
{
	char	*stash;
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	stash = ft_strndup("", 0);
	if (stash == NULL)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		stash = ft_join(stash, buffer);
		if (stash == NULL)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	return (stash);
}
