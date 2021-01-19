/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkapolly <alkapolly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 20:23:28 by alkapolly         #+#    #+#             */
/*   Updated: 2020/11/29 20:34:15 by alkapolly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	free_map(char ***map)
{
	int		y;
	char	**ptr;

	y = -1;
	ptr = *map;
	while (ptr[++y])
		ft_strdel(&ptr[y]);
	free(ptr);
	*map = NULL;
}

void	clean_and_exit(t_mlx **mlx)
{
	t_mlx	*ptr;

	ptr = *mlx;
	if (*mlx)
	{
		if ((*mlx)->img)
			mlx_destroy_image((*mlx)->mlx_ptr, (*mlx)->img);
		if ((*mlx)->win_ptr)
			mlx_destroy_window((*mlx)->mlx_ptr, (*mlx)->win_ptr);
		if ((*mlx)->mlx_ptr)
			free((*mlx)->mlx_ptr);
		if ((*mlx)->map)
			free_map(&((*mlx)->map));
	}
	free(ptr);
	*mlx = NULL;
	exit(EXIT_SUCCESS);
}
