/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:53:46 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/16 13:33:08 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		start;
	int		end;
	int		s1_len;
	int		len;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	s1_len = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (ft_strchr(set, s1[start]) && s1[start] != '\0')
		start++;
	end = s1_len;
	while (ft_strchr(set, s1[end]) && end > 0)
		end--;
	if (start <= end)
		len = end - start + 1;
	else
		len = s1_len - end - start;
	res = ft_substr(s1, start, len);
	if (res == NULL)
		return (NULL);
	return (res);
}

/* #include <stdio.h>
int	main()
{
	char *s = ft_strtrim("abcd", "");
	printf("%s", s);
	free(s);
} */