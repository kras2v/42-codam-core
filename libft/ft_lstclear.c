/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:13:41 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/16 18:29:56 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *curr;
	t_list *next;

	if (*lst == NULL)
		return ;
	curr = *lst;
	while (curr != NULL)
	{
		del(curr->content);
		next = curr->next;
		free(curr);
		curr = next;
	}
	*lst = NULL;
}