/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkapolly <alkapolly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:31:44 by alkapolly         #+#    #+#             */
/*   Updated: 2020/11/28 21:31:50 by alkapolly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_filler	*init_filler(void)
{
	t_filler	*filler;

	if (!(filler = ft_memalloc(sizeof(t_filler))))
		return (NULL);
	filler->map = NULL;
	filler->tetra = NULL;
	filler->bestx = 0;
	filler->besty = 0;
	filler->enemy = 0;
	filler->player = 0;
	return (filler);
}

int			init_map(t_filler *filler)
{
	if (!(filler->map = ft_memalloc(sizeof(t_map))))
		return (0);
	filler->map->heatmap = NULL;
	filler->map->height = 0;
	filler->map->width = 0;
	return (1);
}

int			init_hmap(t_filler *filler)
{
	int		y;

	y = -1;
	if (!(filler->map->heatmap = (int **)malloc(sizeof(int *) \
	* (filler->map->height + 1))))
		return (0);
	while (++y < filler->map->height)
	{
		if (!(filler->map->heatmap[y] = (int *)ft_memalloc(sizeof(int) \
		* filler->map->width)))
			return (0);
	}
	filler->map->heatmap[filler->map->height] = NULL;
	return (1);
}

int			init_tetra(t_filler *filler)
{
	if (!(filler->tetra = ft_memalloc(sizeof(t_tetra))))
		return (0);
	filler->tetra->map = NULL;
	filler->tetra->height = 0;
	filler->tetra->width = 0;
	filler->tetra->miny = 2147483647;
	filler->tetra->minx = 2147483647;
	filler->tetra->maxy = 0;
	filler->tetra->maxx = 0;
	return (1);
}
