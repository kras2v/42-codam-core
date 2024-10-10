/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:59:34 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/10 16:07:31 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/* static void func(unsigned int index, char *c)
{
	*c += index;
}

#include <stdio.h>
int	main()
{
	void (*pointer_func)(unsigned int, char*) = func;
	char res[] = "abc";
	ft_striteri(res, pointer_func);
	printf("%s", res);
} */