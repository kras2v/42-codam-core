/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:07:50 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/09 18:12:50 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char c)
{
	int	words;

	words = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
			words++;
		while (*s != c && *s != '\0')
			s++;
		s++;
	}
	return (words);
}

static int	ft_count_word_len(const char *s, char c)
{
	int	word_len;

	word_len = 0;
	while (*s != c && *s != '\0')
	{
		word_len++;
		s++;
	}
	return (word_len);
}

int	ft_is_res_word_index(char **res, int words_index)
{
	int	j;

	j = 0;
	if (!res[words_index])
	{
		while (j < words_index)
		{
			free(res[j]);
			j++;
		}
		free(res);
		return (0);
	}
	return (1);
}

static char	*ft_write_into_word(const char **src, char *dest, char c)
{
	char	*p_dest;

	p_dest = dest;
	while (**src != c && **src != '\0')
	{
		*p_dest = **src;
		p_dest++;
		(*src)++;
	}
	*p_dest = '\0';
	return (dest);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		words_index;
	int		word_len;

	res = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	words_index = 0;
	if (!res)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		word_len = ft_count_word_len(s, c);
		if (word_len != 0)
		{
			res[words_index] = (char *)malloc((word_len + 1) * sizeof(char));
			if (!ft_is_res_word_index(res, words_index))
				return (NULL);
			ft_write_into_word(&s, res[words_index++], c);
		}
	}
	res[words_index] = NULL;
	return (res);
}

/* #include <stdio.h>
int	main()
{
	char	*s = "hello 1 world k ";
	char	**res = ft_split(s, ' ');
	int	i = 0;
	while(res[i] != NULL)
		printf("%s|", res[i++]);
	i = 0;
	while (res[i] != NULL)
	{
		free(res[i]);
		i++;
	}
	free(res);
		return (0);
} */