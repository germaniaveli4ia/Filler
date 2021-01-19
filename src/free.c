/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkapolly <alkapolly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 20:23:28 by alkapolly         #+#    #+#             */
/*   Updated: 2020/11/28 21:16:11 by alkapolly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_map(int ***hmap)
{
	int		y;
	int		**ptr;

	y = -1;
	ptr = *hmap;
	while (ptr[++y])
	{
		free(ptr[y]);
		ptr[y] = NULL;
	}
	free(ptr);
	*hmap = NULL;
}

void	free_tetramap(char ***tetramap)
{
	int		y;
	char	**ptr;

	y = -1;
	ptr = *tetramap;
	while (ptr[++y])
		ft_strdel(&ptr[y]);
	free(ptr);
	*tetramap = NULL;
}

void	free_tetra(t_tetra **tetra)
{
	int		y;
	t_tetra	*ptr;

	y = -1;
	ptr = *tetra;
	if (ptr)
	{
		while (++y < ptr->height)
		{
			ft_strdel(&(ptr->map[y]));
		}
		free(ptr->map);
		ptr->map = NULL;
		free(ptr);
		*tetra = NULL;
	}
}

void	clean_and_exit(t_filler **filler)
{
	t_filler	*ptr;

	ptr = *filler;
	if (*filler)
	{
		if ((*filler)->map)
		{
			if ((*filler)->map->heatmap)
				free_map(&((*filler)->map->heatmap));
			free((*filler)->map);
			(*filler)->map = NULL;
		}
		if ((*filler)->tetra)
		{
			if ((*filler)->tetra->map)
				free_tetramap(&((*filler)->tetra->map));
			free(&((*filler)->tetra));
			(*filler)->tetra = NULL;
		}
	}
	free(ptr);
	*filler = NULL;
	exit(EXIT_SUCCESS);
}
