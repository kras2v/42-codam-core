/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:16:09 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/30 18:48:17 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

//! to remove
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strchr(const char *s, int c);
char	*ft_realloc(char *input, char *buffer, 
		int total_size, int bytes_read);
int	ft_get_new_line_index(char *buffer, int bytes_read);

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

#endif
