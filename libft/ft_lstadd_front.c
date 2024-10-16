/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 16:02:49 by kvalerii          #+#    #+#             */
/*   Updated: 2024/10/16 17:57:40 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/* #include <stdio.h>
int	main(void)
{
	t_list *root = ft_lstnew((void *)1);
	t_list *el2 = ft_lstnew((void *)2);
	t_list *el3 = ft_lstnew((void *)3);

	t_list *lst[3];
	//ft_lstadd_front(lst, root);
	printf("%d", root->content);
}
 */