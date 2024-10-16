/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:14:46 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/16 17:53:27 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	curr = *lst;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new;
}

/* #include <stdio.h>
int	main(void)
{
	t_list *root = ft_lstnew((void *)1);
	t_list *el2 = ft_lstnew((void *)2);
	ft_lstadd_back(&root, el2);
	// t_list *el3 = ft_lstnew((void *)3);
	printf("%d", root->next->content);
} */