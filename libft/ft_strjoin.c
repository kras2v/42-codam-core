/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriia <valeriia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:17:59 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/09 23:16:30 by valeriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_join(char *res, char const *s)
{
	while (*s != '\0')
		*res++ = *s++;
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	char	*p_res;

	res = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	p_res = res;
	p_res = ft_join(p_res, s1);
	p_res = ft_join(p_res, s2);
	*p_res = '\0';
	return (res);
}

/* #include <stdio.h>
int	main(void)
{
	char *s1 = "Hello, ";
	char *s2 = "World!";

	char *res = ft_strjoin(s1, s2);
	printf("%s", res);
	free(res);
} */