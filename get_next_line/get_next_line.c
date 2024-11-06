/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:16:08 by kvalerii          #+#    #+#             */
/*   Updated: 2024/11/05 21:50:25 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_allocate_new_line(t_stash *stash)
{
	char *res;

	if (stash->contains_new_line)
		stash->new_line_index++;
	else
		stash->new_line_index = stash->total_size;
	res = ft_strndup(stash->stash, stash->new_line_index);
	return (res);
}

char	*ft_create_new_stash(t_stash *stash)
{
	char *res;

	if (!stash->contains_new_line)
	{
		free(stash->stash);
		return (ft_strndup("", 0));
	}
	res = ft_strndup(stash->stash + stash->new_line_index, 
		stash->total_size - stash->new_line_index);
	free(stash->stash);
	stash->stash = NULL;
	return (res);
}

char	*generate_new_line(t_stash *stash, char *buffer)
{
	char	*line;

	line = NULL;
	line = ft_allocate_new_line(stash);
	if (!line)
	{
		free(stash->stash);
		stash->stash = NULL;
		free(buffer);
		return (NULL);
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

char	*get_next_line(int fd)
{
	static t_stash	stash;
	char			*buffer;
	ssize_t			bytes_read;

	if (stash.stash == NULL)
		stash.stash = ft_strndup("", 0);
	if (!stash.stash)
		return free_all_and_return_null(&stash, NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return free_all_and_return_null(&stash, buffer);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	stash.total_size = ft_strlen(stash.stash);
	while(bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		stash.stash = ft_strjoin_and_free(stash.stash, buffer);
		if (!stash.stash)
			return free_all_and_return_null(&stash, buffer);
		stash.total_size += bytes_read;
		if (ft_any(&stash, '\n'))
			return generate_new_line(&stash, buffer);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (stash.total_size > 0 && bytes_read == 0)
	{
		stash.contains_new_line = ft_any(&stash, '\n');
		return generate_new_line(&stash, buffer);
	}
	return free_all_and_return_null(&stash, buffer);
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

// #include <time.h>
// int  ft_run(void)
// {
//   int    fd;
//   char  *p;

//   fd = open("test.txt", O_RDONLY);
//   p = get_next_line(fd);
//   while (p != NULL)
//   {
//     printf("%s", p);
//     free(p);
//     p = get_next_line(fd);
//   }
//   printf("%s", p);
//   return (0);
// }

// int main() {
//     // Start time
//     clock_t start_time = clock();

//     // Code to measure
//   ft_run();

//     // End time
//     clock_t end_time = clock();

//     // Calculate the elapsed time in milliseconds
//     double time_taken = ((double)(end_time - start_time) / CLOCKS_PER_SEC) * 1000.0;

//     printf("\nExecution time: %.3f ms\n", time_taken);

//     return 0;
// }