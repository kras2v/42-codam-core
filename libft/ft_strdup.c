/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:59:53 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/18 16:58:36 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	int		s_len;

	s_len = ft_strlen(s);
	res = (char *)malloc((s_len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s, s_len + 1);
	return (res);
}
