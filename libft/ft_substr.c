/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:55:03 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/11 16:38:46 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	const char		*s_end;
	size_t			i;

	if (!s)
		return (NULL);
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	s_end = s + ft_strlen(s);
	while (i < len && (s + i + start) <= s_end)
	{
		res[i] = s[i + start];
		i++;
	}
	res[i] = '\0';
	return (res);
}
/* #include <stdio.h>
int	main()
{
	char *s = ft_substr("l", 1, 10);
	printf("%s", s);
	free(s);
} */