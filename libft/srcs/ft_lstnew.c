/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkapolly <alkapolly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 01:04:46 by alkapolly         #+#    #+#             */
/*   Updated: 2020/11/29 01:04:48 by alkapolly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *node;

	node = (t_list*)ft_memalloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	if (!content)
	{
		node->content = NULL;
		node->content_size = 0;
	}
	else
	{
		node->content = ft_memdup(content, content_size);
		if (!node->content)
		{
			free(node);
			return (NULL);
		}
		node->content_size = content_size;
	}
	return (node);
}
