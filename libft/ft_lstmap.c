/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 18:35:18 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/16 18:55:56 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *res;
	t_list *next;
	
	res = (t_list *)malloc(sizeof(t_list));
	if (!res || !lst)
		return (NULL);
	while (lst != NULL)
	{
		res->content = f(lst->content);
		next = (t_list *)malloc(sizeof(t_list));
		if (!next)
		{
			ft_lstclear(&next, del);
			return res;
		}
		ft_lstadd_back(&res, next);
		lst = lst->next;
	}
	return (res);
}
