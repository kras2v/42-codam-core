/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:55:03 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/09 16:53:05 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*res;
	size_t		i;

	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res || start > ft_strlen(s))
		return (NULL);
	i = 0;
	while (i < len && s[i + start] != '\0')
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
	char *s = ft_substr("Hello, World!", 10, 3);
	printf("%s", s);
	free(s);
} */