/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_put_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkapolly <alkapolly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 01:05:38 by alkapolly         #+#    #+#             */
/*   Updated: 2020/11/29 01:05:40 by alkapolly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_put_last(t_list *lst, void *content)
{
	t_list	*tmp;
	t_list	*last;

	tmp = ft_lstnew(content, ft_strlen((const char *)content));
	if (lst == NULL)
		lst = tmp;
	else
	{
		last = ft_lstlast(lst);
		last->next = tmp;
	}
	return (lst);
}
