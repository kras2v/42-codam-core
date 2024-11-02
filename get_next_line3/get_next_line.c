/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:26:12 by kvalerii          #+#    #+#             */
/*   Updated: 2024/11/02 12:34:46 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strncpy(char *dst, const char *src, size_t size)
{
	size_t i;

	i = 0;
	while (src[i] != '\0' && i < size)
	{
		dst[i] = src[i];
		i++;
	}
	while (i < size)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}

char	*ft_strndup(char *src, size_t size)
{
	char *res;

	res = malloc(size + 1);
	if (!res)
		return (NULL);
	ft_strncpy(res, src, size);
	res[size] = '\0';
	return (res);
}

char	*ft_strjoin(char *stash, char *buffer, 
		size_t size, size_t bytes_read)
{
	char	*res;

	res = malloc((size + bytes_read) + 1);
	if (!res)
		return (NULL);
	ft_strncpy(res, stash, size);
	ft_strncpy(res + size, buffer, bytes_read);
	res[size + bytes_read] = '\0';
	free(stash);
	return (res);
}

size_t	ft_find_index_in_range(char *s, char c, size_t start, size_t end)
{
	while(start < end && *s)
	{
		if (s[start] == c)
			return (start);
		start++;
	}
	return (end);
}

char	*ft_create_new_stash(char *old_stash, size_t new_line, size_t total_size)
{
	char	*new_stash;

	if (new_line > total_size)
	{
		free(old_stash);
		return (ft_strndup("", 1));
	}
	new_stash = ft_strndup(old_stash + new_line, total_size - new_line);
	if (!new_stash)
		return (NULL);
	free(old_stash);
	return (new_stash);
}

char	*ft_assign_new_line_and_clean_stash(char **stash, size_t new_line_index, size_t total_size)
{
	char *line;

	if (new_line_index > total_size)
		new_line_index = total_size - 1;
	line = ft_strndup(*stash, new_line_index + 1);
	if (!line)
		return (NULL);
	(*stash) = ft_create_new_stash((*stash), new_line_index + 1, total_size);
	if (!(*stash))
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char *get_next_line(int fd)
{
	static char	*stash;
	ssize_t		bytes_read;
	size_t		total_size;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	size_t		new_line_index;

	if (fd < 0)
		return (NULL);
	if(!stash)
	{
		stash = ft_strndup("", 1);
		if (!stash)
			return (NULL);
	}
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		//free(stash);
		return (NULL);
	}
	total_size = ft_strlen(stash);
	line = NULL;
	while (bytes_read > 0)
	{
		buffer[bytes_read] = 0;
		stash = ft_strjoin(stash, buffer, total_size, bytes_read);
		total_size += bytes_read;
		if (ft_find_index_in_range(buffer, '\n', 0, bytes_read) == bytes_read)
		{
			new_line_index = ft_find_index_in_range(stash, '\n', 0, total_size);
			if (bytes_read < BUFFER_SIZE && new_line_index > total_size)
				new_line_index = total_size;
			if (new_line_index <= total_size)
			{
				line = ft_assign_new_line_and_clean_stash(&stash, new_line_index, total_size);
				if (!line)
				{
					free(stash);
				}
				return (line);
			}
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(stash);
			return (NULL);
		}
	}
	if (bytes_read == 0 && total_size > 0)
	{
		new_line_index = ft_find_index_in_range(stash, '\n', 0, total_size);
		if (new_line_index == total_size)
			new_line_index = total_size - 1;
		line = ft_assign_new_line_and_clean_stash(&stash, new_line_index, total_size);
		return (line);
	}
	if (bytes_read == 0 && !line)
	{
		if (stash)
			free(stash);
		stash = NULL;
	}
	return (NULL);
}

// int	main(void)
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	// char c;
// 	while ((1))
// 	{
// 		// scanf("%c", &c);
// 		char *r = get_next_line(fd);
// 		if (r == NULL)
// 			break;
// 		printf("%s", r);
// 		free(r);
// 	}
// 	char *r = get_next_line(fd);
// 	printf("%s", r);
// 	close(fd);
// 	return (0);
// }