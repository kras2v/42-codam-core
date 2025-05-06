/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 20:46:50 by kvalerii          #+#    #+#             */
/*   Updated: 2025/05/06 20:47:01 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

void	ft_puterror(char *msg)
{
	write(2, msg, ft_strlen(msg));
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;
	char	*p_alloc;
	size_t	i;

	alloc = malloc(nmemb * size);
	if (alloc == NULL)
	{
		ft_puterror("Error allocating memory");
		return (NULL);
	}
	i = 0;
	p_alloc = (char *)alloc;
	while (i < nmemb * size)
	{
		*p_alloc = 0;
		p_alloc++;
		i++;
	}
	return (alloc);
}
