/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkapolly <alkapolly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 00:57:40 by alkapolly         #+#    #+#             */
/*   Updated: 2020/11/29 00:57:41 by alkapolly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *ptr;

	ptr = (char *)s;
	while (*ptr)
		ptr++;
	while (ptr != s && *ptr != (char)c)
		ptr--;
	if (*ptr == (char)c)
		return (ptr);
	return (NULL);
}
