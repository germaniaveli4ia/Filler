/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkapolly <alkapolly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 01:05:45 by alkapolly         #+#    #+#             */
/*   Updated: 2020/11/29 01:05:47 by alkapolly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	if (n == LIBFT_MAX_INT * -1)
		return (ft_strdup("-2147483648"));
	sign = (n < 0) ? 1 : 0;
	n = (n < 0) ? n * -1 : n;
	len = ft_intlen(n) + sign;
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	str[len--] = '\0';
	while (len - sign >= 0)
	{
		str[len--] = n % 10 + '0';
		n /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}
