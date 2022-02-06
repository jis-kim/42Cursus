/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 15:03:18 by jiskim            #+#    #+#             */
/*   Updated: 2021/05/17 15:58:00 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*node;

	new_list = NULL;
	if (!lst)
		return (NULL);
	node = lst;
	while (node)
	{
		new_node = ft_lstnew(f(node->content));
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
		}
		ft_lstadd_back(&new_list, new_node);
		node = node->next;
	}
	return (new_list);
}
