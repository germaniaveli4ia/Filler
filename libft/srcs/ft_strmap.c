/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkapolly <alkapolly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 00:55:31 by alkapolly         #+#    #+#             */
/*   Updated: 2020/11/29 00:55:33 by alkapolly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	ptr = ft_strnew(ft_strlen(s));
	if (ptr == NULL)
		return (NULL);
	while (s[i])
	{
		ptr[i] = f(s[i]);
		i++;
	}
	return (ptr);
}
