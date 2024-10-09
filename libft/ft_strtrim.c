/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:53:46 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/09 17:03:39 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_set(const char *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*res;
	char		*p_res;
	const char	*s1_end;
	int			s1_len;

	s1_len = ft_strlen(s1);
	res = (char *)malloc((s1_len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	p_res = res;
	s1_end = s1 + s1_len - 1;
	while (ft_is_in_set(set, *s1))
		s1++;
	while (ft_is_in_set(set, *s1_end))
		s1_end--;
	while (s1 != s1_end)
		*p_res++ = *s1++;
	*p_res = '\0';
	return (res);
}

/* #include <stdio.h>
int	main()
{
	char *s = ft_strtrim("  1 3 5    Hello, World!  1 3 5    ", " 135");
	printf("%s", s);
	free(s);
} */