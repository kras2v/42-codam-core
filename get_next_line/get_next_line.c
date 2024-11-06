/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:16:08 by kvalerii          #+#    #+#             */
/*   Updated: 2024/11/06 11:17:05 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_allocate_new_line(t_stash *stash)
{
	char	*res;
	size_t	total_size;

	stash->contains_new_line = ft_any(stash, '\n');
	total_size = ft_strlen(stash->stash);
	if (stash->contains_new_line)
		stash->new_line_index++;
	else
		stash->new_line_index = total_size;
	res = ft_strndup(stash->stash, stash->new_line_index);
	return (res);
}

char	*ft_create_new_stash(t_stash *stash)
{
	char	*res;
	size_t	total_size;

	if (!stash->contains_new_line)
	{
		free(stash->stash);
		return (ft_strndup("", 0));
	}
	total_size = ft_strlen(stash->stash);
	res = ft_strndup(stash->stash + stash->new_line_index,
			total_size - stash->new_line_index);
	free(stash->stash);
	stash->stash = NULL;
	return (res);
}

char	*free_all_and_return_null(t_stash *stash, char *buffer)
{
	if (stash->stash != NULL)
	{
		free(stash->stash);
		stash->stash = NULL;
	}
	if (buffer != NULL)
	{
		free(buffer);
	}
	return (NULL);
}

char	*generate_new_line(t_stash *stash, char *buffer)
{
	char	*line;

	line = NULL;
	line = ft_allocate_new_line(stash);
	if (!line)
	{
		return (free_all_and_return_null(stash, buffer));
	}
	stash->stash = ft_create_new_stash(stash);
	if (!stash->stash)
	{
		free(buffer);
		free(line);
		return (NULL);
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_stash	stash;
	char			*buffer;
	ssize_t			bytes_read;

	if (stash.stash == NULL)
		stash.stash = ft_strndup("", 0);
	if (!stash.stash)
		return (free_all_and_return_null(&stash, NULL));
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free_all_and_return_null(&stash, buffer));
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		stash.stash = ft_append_buffer_to_stash(stash.stash,
				buffer, bytes_read);
		if (!stash.stash)
			return (free_all_and_return_null(&stash, buffer));
		if (ft_any(&stash, '\n'))
			return (generate_new_line(&stash, buffer));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (ft_strlen(stash.stash) > 0 && bytes_read == 0)
		return (generate_new_line(&stash, buffer));
	return (free_all_and_return_null(&stash, buffer));
}

/* int	main(void)
{
	int		fd = open("test.txt", O_RDONLY);
	char	*res = 	NULL;
	//char c;
	while(fd >= 0)
	{
		// scanf("%c", &c);
		res = get_next_line(fd);
		printf("%s", res);
		if(res == NULL)
			break;
		free(res);
	}
	return (0);
} */
