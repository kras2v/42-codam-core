/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:55:03 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/16 15:26:20 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_alloc_empty_str(void)
{
	char	*res;

	res = malloc(1);
	if (!res)
		return (NULL);
	*res = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		total;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_alloc_empty_str());
	if (len < (s_len - start))
		total = len;
	else
		total = s_len - start;
	res = (char *)malloc((total + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len && s[i + start] != '\0')
	{
		res[i] = s[i + start];
		i++;
	}
	res[i] = 0;
	return (res);
}

/* #include <stdio.h>
int	main()
{
	char *s = ft_substr("hola", 2, 3);
	printf("%s", s);
	free(s);
} */