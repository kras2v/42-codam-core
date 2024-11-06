/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:16:08 by kvalerii          #+#    #+#             */
/*   Updated: 2024/11/06 19:04:40 by kvalerii         ###   ########.fr       */
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

void	ft_lstclear(t_stash **lst)
{
	t_stash	*curr;
	t_stash	*next;

	if (!lst)
		return ;
	curr = (*lst);
	while (curr != NULL)
	{
		next = curr->next;
		free(curr->stash);
		curr->stash = NULL;
		free(curr);
		curr = next;
	}
	(*lst) = NULL;
}

void	remove_element(t_stash **lst, int fd)
{
	t_stash *curr;
	t_stash *to_remove;
	
	if ((*lst) == NULL)
		return ;
	if((*lst)->fd = fd)
	{
		to_remove = (*lst);
		(*lst) = (*lst)->next;
		free(to_remove->stash);
		free(to_remove);
		return ;
	}
	curr = (*lst);
	while (curr->next != NULL)
	{
		if (curr->next->fd == fd)
		{
			to_remove = (curr->next);
			curr->next = to_remove->next;
			free(to_remove->stash);
			free(to_remove);
			return ;
		}
	}
}

char	*free_all_and_return_null(char *stash, char *buffer, t_stash **list, int fd)
{
	if (stash != NULL)
	{
		free(stash);
		stash = NULL;
	}
	if (buffer != NULL)
	{
		free(buffer);
	}
	if (fd > 0)
	{
		remove_element(list, fd);
		return (NULL);
	}
	ft_lstclear(list);
	return (NULL);
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
	free_all_and_return_null(stash->stash, 0, 0, -1);
	return (res);
}

char	*ft_create_new_line_and_stash(t_stash *stash, char *buffer, t_stash **lst, int fd)
{
	char	*line;
	size_t	total_size;

	line = NULL;
	stash->contains_new_line = ft_any(stash, '\n');
	total_size = ft_strlen(stash->stash);
	if (stash->contains_new_line)
		stash->new_line_index++;
	else
		stash->new_line_index = total_size;
	line = ft_strndup(stash->stash, stash->new_line_index);
	if (line == NULL)
	{
		return (free_all_and_return_null(0, buffer, lst, fd));
	}
	stash->stash = ft_create_new_stash(stash);
	if (stash->stash == NULL)
	{
		free(buffer);
		free(line);
		return (NULL);
	}
	free(buffer);
	return (line);
}

char	*ft_append_buffer_to_stash(char *stash,
	char *buffer, ssize_t bytes_read)
{
	char	*res;

	buffer[bytes_read] = '\0';
	res = ft_strjoin(stash, buffer);
	if (!res)
	{
		free(stash);
		return (NULL);
	}
	free(stash);
	return (res);
}

t_stash	*ft_lstnew(int fd)
{
	t_stash	*node;

	node = (t_stash *)malloc(sizeof(t_stash));
	if (!node)
		return (NULL);
	node->fd = fd;
	node->stash = NULL;
	node->contains_new_line = 0;
	node->new_line_index = 0;
	node->next = NULL;
	return (node);
}

void	ft_lstadd_back(t_stash **lst, t_stash *new)
{
	t_stash	*curr;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		curr = *lst;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = new;
	}
}

t_stash	*get_stash_by_fd(t_stash *lst, int fd)
{
	t_stash	*curr;
	t_stash	*p_lst;

	if (!lst)
		return (NULL);
	p_lst = lst;
	while (p_lst != NULL && p_lst->fd != fd)
		p_lst = p_lst->next;
	if (p_lst == NULL)
	{
		curr = ft_lstnew(fd);
		ft_lstadd_back(&lst, curr);
	}
	else
		return (p_lst);
	return (curr);
}

char	*get_next_line(int fd)
{
	t_stash	*curr;
	char	*buffer;
	ssize_t	bytes_read;
	static t_stash	*root;

	if (root == NULL)
	{
		root = ft_lstnew(fd);
		curr = root;
	}
	else 
	{
		curr = get_stash_by_fd(root, fd);
	}
	if (curr->stash == NULL)
		curr->stash = ft_strndup("", 0);
	if (curr->stash == NULL)
		return (free_all_and_return_null(curr, NULL, &root, -1));
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (free_all_and_return_null(curr, buffer, &root, -1));
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		curr->stash = ft_append_buffer_to_stash(curr->stash,
				buffer, bytes_read);
		if (curr->stash == NULL)
			return (free_all_and_return_null(0, buffer, &root, fd));
		if (ft_any((curr), '\n'))
			return (ft_create_new_line_and_stash(curr, buffer, &root, fd));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (ft_strlen(curr->stash) > 0 && bytes_read == 0)
		return (ft_create_new_line_and_stash(curr, buffer, &root, fd));
	return (free_all_and_return_null(0, buffer, &root, fd));
}

int	main(void)
{
	int		fd1 = open("test1.txt", O_RDONLY);
	int		fd2 = open("test2.txt", O_RDONLY);
	int		fd3 = open("test3.txt", O_RDONLY);
	char	*res = 	NULL;
	int fds[3] = {fd1, fd2, fd3};
	int index = 0;
	int counter = 0;
	//char c;
	while(counter < 10)
	{
		// scanf("%c", &c);
		res = get_next_line(fds[index]);
		printf("%s", res);
		free(res);
		index++;
		counter++;
		if (index == 3)
			index = 0;
	}
	return (0);
}