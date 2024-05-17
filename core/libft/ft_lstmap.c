/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpelikan <rpelikan@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:20:54 by rpelikan          #+#    #+#             */
/*   Updated: 2024/05/16 20:15:48 by rpelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*start;

	if (!lst || !f || !del)
		return (NULL);
	start = 0;
	while (lst)
	{
		new_lst = ft_lstnew((*f)(lst->content));
		if (!new_lst)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		else
			ft_lstadd_back(&start, new_lst);
		lst = lst->next;
	}
	return (start);
}
