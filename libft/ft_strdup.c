/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 17:59:53 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/08 18:24:31 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p_s;
	int		i;

	p_s = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	i = 0;
	while(s[i] != '\0')
	{
		p_s[i] = s[i];
		i++;
	}
	p_s[i] = '\0';
	return (p_s);
}

#include <stdio.h>
int	main(void)
{
	char *dest;
	char src[6] = "";

	dest = ft_strdup(src);
	printf("%s\n", dest);
	free(dest);

	char *dest1;
	char src1[6] = "";

	dest1 = ft_strdup(src1);
	printf("%s\n", dest1);
	free(dest1);
} 