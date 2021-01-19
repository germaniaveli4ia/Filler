/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkapolly <alkapolly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 01:03:20 by alkapolly         #+#    #+#             */
/*   Updated: 2020/11/29 01:03:22 by alkapolly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = -1;
	ptr = (unsigned char *)b;
	while (++i < n)
		ptr[i] = (unsigned char)c;
	return (b);
}
