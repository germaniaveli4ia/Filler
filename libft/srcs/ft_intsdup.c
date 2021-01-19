/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkapolly <alkapolly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 01:09:02 by alkapolly         #+#    #+#             */
/*   Updated: 2020/11/29 01:09:04 by alkapolly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_intsdup(int *arr, size_t size)
{
	int		*duplicate;
	size_t	i;

	i = 0;
	duplicate = (int *)malloc(sizeof(int) * size);
	if (!duplicate)
		return (NULL);
	while (i < size)
	{
		duplicate[i] = arr[i];
		i++;
	}
	return (duplicate);
}
