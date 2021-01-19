/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkapolly <alkapolly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 00:58:19 by alkapolly         #+#    #+#             */
/*   Updated: 2020/11/29 00:58:20 by alkapolly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;

	if (s == NULL)
		return (NULL);
	start = 0;
	while (ft_isspace(s[start]))
		start++;
	if (s[start] == '\0')
		return (ft_strnew(0));
	end = ft_strlen(s) - 1;
	while (ft_isspace(s[end]))
		end--;
	return (ft_strsub(s, start, end - start + 1));
}
