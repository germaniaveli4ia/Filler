/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkapolly <alkapolly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 01:05:20 by alkapolly         #+#    #+#             */
/*   Updated: 2020/11/29 01:05:22 by alkapolly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	if (alst == NULL || del == NULL)
		return ;
	while ((*alst) != NULL)
	{
		tmp = *alst;
		*alst = (*alst)->next;
		ft_lstdelone(&tmp, del);
	}
}
