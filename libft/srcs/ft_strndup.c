/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkapolly <alkapolly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 00:57:00 by alkapolly         #+#    #+#             */
/*   Updated: 2020/11/29 00:57:02 by alkapolly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t len)
{
	char *dst;

	dst = ft_strnew(len);
	if (dst == NULL)
		return (NULL);
	dst = ft_strncpy(dst, src, len);
	return (dst);
}
