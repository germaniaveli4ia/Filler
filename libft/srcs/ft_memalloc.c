/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkapolly <alkapolly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 01:04:25 by alkapolly         #+#    #+#             */
/*   Updated: 2020/11/29 01:04:27 by alkapolly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*obj;

	obj = 0;
	if (!(obj = malloc(size)))
		return (NULL);
	ft_memset(obj, 0, size);
	return (obj);
}
