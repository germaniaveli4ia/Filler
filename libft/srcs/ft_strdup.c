/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkapolly <alkapolly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 01:00:16 by alkapolly         #+#    #+#             */
/*   Updated: 2020/11/29 01:00:18 by alkapolly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*new;
	size_t	len;

	len = ft_strlen(src);
	new = ft_strnew(len);
	if (new == NULL)
		return (NULL);
	new = (char *)ft_memcpy(new, src, len);
	return (new);
}
