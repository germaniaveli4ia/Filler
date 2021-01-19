/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkapolly <alkapolly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 00:55:09 by alkapolly         #+#    #+#             */
/*   Updated: 2020/11/29 00:55:11 by alkapolly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t dst_len;
	size_t src_len;
	size_t final_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	final_len = (dst_len < size) ? dst_len : size;
	if (src_len < size - final_len)
		ft_strncat(dst, src, src_len + 1);
	else if (size > final_len)
	{
		ft_strncat(dst, src, size - final_len - 1);
		dst[size - 1] = '\0';
	}
	return (final_len + src_len);
}
