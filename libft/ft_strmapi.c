/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:45:22 by valeriia          #+#    #+#             */
/*   Updated: 2024/10/10 17:40:16 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	res = ft_strdup(s);
	if (!res)
		return (NULL);
	while (res[i] != '\0')
	{
		res[i] = f(i, res[i]);
		i++;
	}
	return (res);
}

/* static char func(unsigned int index, char c)
{
	return (c + index);
}
#include <stdio.h>
int	main()
{
	char (*pointer_func)(unsigned int, char) = func;
	char *res = ft_strmapi("abc", pointer_func);
	printf("%s", res);
} */