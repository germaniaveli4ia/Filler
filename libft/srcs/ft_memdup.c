/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkapolly <alkapolly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 01:03:38 by alkapolly         #+#    #+#             */
/*   Updated: 2020/11/29 01:03:39 by alkapolly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(void const *src, size_t size)
{
	unsigned char	*dst;

	if (src == NULL)
		return (NULL);
	dst = (unsigned char*)ft_memalloc(size);
	if (dst == NULL)
		return (NULL);
	return (ft_memcpy(dst, src, size));
}
