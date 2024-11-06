/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:16:09 by kvalerii          #+#    #+#             */
/*   Updated: 2024/11/06 19:04:10 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

//! to remove
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

typedef struct s_stash
{
	int				fd;
	char			*stash;
	int				contains_new_line;
	size_t			new_line_index;
	struct s_stash	*next;
}	t_stash;

char	*get_next_line(int fd);
char	*ft_strndup(char *str, size_t size);
size_t	ft_strlen(char *s);
char	*ft_append_buffer_to_stash(char *stash,
			char *buffer, ssize_t bytes_read);
int		ft_any(t_stash *stash, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_create_new_line_and_stash(t_stash *stash, char *buffer, t_stash **lst, int fd);
char	*free_all_and_return_null(char *stash, char *buffer, t_stash **list, int fd);
char	*ft_create_new_stash(t_stash *stash);
char	*get_next_line(int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

#endif
