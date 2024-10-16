/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:22:12 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/16 15:34:00 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*p_s_end;
	unsigned char	*p_s_start;

	p_s_start = (unsigned char *)s;
	p_s_end = (unsigned char *)s + ft_strlen(s);
	while (p_s_end >= p_s_start)
	{
		if (*p_s_end == (unsigned char)c)
			return ((char *)p_s_end);
		p_s_end--;
	}
	if (*p_s_end == c)
		return ((char *)p_s_end);
	return (0);
}

/* #include <string.h>
#include <stdio.h>
int	main()
{
	char s[] = "tripouille";
	printf("%s", ft_strrchr(s, 't' + 256));
} */