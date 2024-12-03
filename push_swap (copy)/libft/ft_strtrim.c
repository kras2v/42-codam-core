/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:53:46 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/18 17:47:07 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_calc_start_index(char const *s1, char const *set)
{
	int	start;

	start = 0;
	while (ft_strchr(set, s1[start]) && s1[start] != '\0')
		start++;
	return (start);
}

static int	ft_calc_end_index(char const *s1, char const *set)
{
	int	end;

	end = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[end]) && end > 0)
		end--;
	return (end);
}

static int	ft_calc_len(int start, int end)
{
	int	len;

	if (start > end)
		len = 0;
	else
		len = end - start + 1;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		start;
	int		end;
	int		len;

	if (!s1 || !set)
		return (NULL);
	start = ft_calc_start_index(s1, set);
	end = ft_calc_end_index(s1, set);
	len = ft_calc_len(start, end);
	res = ft_substr(s1, start, len);
	if (!res)
		return (NULL);
	return (res);
}
