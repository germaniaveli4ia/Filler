/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkapolly <alkapolly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 00:57:57 by alkapolly         #+#    #+#             */
/*   Updated: 2020/11/29 00:57:59 by alkapolly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t k;
	size_t hay_len;
	size_t nee_len;

	if (*needle == '\0' || haystack == needle)
		return ((char *)haystack);
	i = 0;
	nee_len = ft_strlen(needle);
	hay_len = ft_strlen(haystack);
	if (hay_len < nee_len)
		return (NULL);
	while (i < hay_len - nee_len + 1)
	{
		k = 0;
		while (k < nee_len && haystack[i + k] == needle[k])
			k++;
		if (needle[k] == '\0')
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
