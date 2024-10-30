/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:16:08 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/30 18:56:06 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(1, &s[i], fd);
		i++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*p_s_end;
	unsigned char	*p_s_start;
	int				str_len;
	
	str_len = 0;
	if (!s)
		return (0);
	while (s[str_len] != '\0')
		str_len++;
	p_s_start = (unsigned char *)s;
	p_s_end = p_s_start + str_len;
	while (p_s_start <= p_s_end)
	{
		if (*p_s_start == (unsigned char)c)
			return ((char *)p_s_start);
		p_s_start++;
	}
	return (0);
}

int	ft_get_new_line_index(char *buffer, int bytes_read)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0' && i <= bytes_read)
		i++;
	return (i);
}

char	*ft_realloc(char *input, char *buffer, 
		int total_size, int bytes_read)
{
	char	*new;
	int		total;
	int		until_new_line;

	until_new_line = ft_get_new_line_index(buffer, bytes_read);
	total = total_size + until_new_line;
	new = malloc(total + 1);
	if (!new)
		return (NULL);
	if (input)
		ft_strncpy(new, input, total_size);
	ft_strncpy(new + total_size, buffer, until_new_line);
	new[total] = '\0';
	free(input);
	return (new);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		*str;
	static char	buffer[BUFFER_SIZE];
	int			total_size;
	int			new_line_index;

	str = malloc(1);
	if (!str)
		return (NULL);
	str[0] = '\0';
	new_line_index = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == -1)
	{
		free (str);
		return (NULL);
	}
	total_size = 0;
	while (bytes_read > 0)
	{
		str = ft_realloc(str, buffer, total_size, bytes_read);
		if (!str)
			return (NULL);
		if (ft_strchr(buffer, '\n') > 0)
			break;
		total_size += bytes_read;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(str);
			return (NULL);
		}
	}
	if (bytes_read == 0 && str[0] == '\0')
	{
		free (str);
		return (NULL);
	}
	return (str);
}

int	main(void)
{
	int		fd;
	char	a;
	char *res;

	fd = open("./test.txt", O_RDONLY);
	if (fd == -1) {
		printf("Error Number");
	}
	int b;
	while (1)
	{
		scanf("%c", &a);
		res = get_next_line(fd);
		if (!res)
			break;
		else
			ft_putstr_fd(res, 1);
	}
	close(fd);
}