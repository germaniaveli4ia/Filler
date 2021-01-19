/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpurge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkapolly <alkapolly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 01:04:33 by alkapolly         #+#    #+#             */
/*   Updated: 2020/11/29 01:04:36 by alkapolly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpurge(t_list *lst)
{
	t_list *tmp;

	while (lst)
	{
		ft_memdel(lst->content);
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}
