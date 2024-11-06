/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:16:09 by kvalerii          #+#    #+#             */
/*   Updated: 2024/11/05 21:36:16 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

//! to remove
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

typedef	struct s_stash
{
	char	*stash;
	size_t	total_size;
	int		contains_new_line;
	size_t	new_line_index;
}	t_stash;

char	*get_next_line(int fd);
char	*ft_strndup(char *str, size_t size);
size_t	ft_strlen(char *s);
char	*ft_strjoin_and_free(char *s1, char *s2);
int		ft_any(t_stash *stash, int c);
char	*ft_allocate_new_line(t_stash *stash);
char	*ft_create_new_stash(t_stash *stash);
char	*get_next_line(int fd);

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

#endif
