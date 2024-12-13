/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 22:45:22 by valeriia          #+#    #+#             */
/*   Updated: 2024/10/18 16:47:26 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	int		i;

	if (!s)
		return (NULL);
	res = ft_strdup(s);
	if (!res)
		return (NULL);
	i = 0;
	while (res[i] != '\0')
	{
		res[i] = f(i, res[i]);
		i++;
	}
	return (res);
}
