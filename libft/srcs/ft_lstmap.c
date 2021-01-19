/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkapolly <alkapolly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 01:04:53 by alkapolly         #+#    #+#             */
/*   Updated: 2020/11/29 01:04:55 by alkapolly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *head;
	t_list *current;

	if (!lst)
		return (NULL);
	head = f(lst);
	if (!head)
		return (NULL);
	current = head;
	while (lst->next)
	{
		lst = lst->next;
		current->next = f(lst);
		if (!current->next)
		{
			ft_lstpurge(lst);
			return (NULL);
		}
		current = current->next;
	}
	return (head);
}
