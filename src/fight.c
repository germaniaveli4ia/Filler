/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fight.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkapolly <alkapolly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 23:25:17 by alkapolly         #+#    #+#             */
/*   Updated: 2020/11/28 21:31:42 by alkapolly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		find_distance(t_filler *filler, int y1, int x1)
{
	int		x2;
	int		y2;
	int		min_distance;
	int		dist;

	y2 = -1;
	min_distance = 2147483647;
	while (++y2 < filler->map->height)
	{
		x2 = -1;
		while (++x2 < filler->map->width)
		{
			if (filler->map->heatmap[y2][x2] == ENEMY)
			{
				dist = ft_abs(y2 - y1) + ft_abs(x2 - x1);
				if (min_distance > dist)
					min_distance = dist;
			}
		}
	}
	return (min_distance);
}

void			calc_heatmap(t_filler *filler)
{
	int		x;
	int		y;

	y = -1;
	while (++y < filler->map->height)
	{
		x = -1;
		while (++x < filler->map->width)
		{
			if (filler->map->heatmap[y][x] == EMPTY)
				filler->map->heatmap[y][x] = find_distance(filler, y, x);
		}
	}
}

static int		find_sum(int y, int x, t_tetra *tetra, t_map *map)
{
	int		ytetra;
	int		xtetra;
	int		player;
	int		sum;

	player = 0;
	ytetra = tetra->miny - 1;
	sum = 0;
	while (++ytetra < tetra->height)
	{
		xtetra = tetra->minx - 1;
		while (++xtetra < tetra->width)
		{
			if (tetra->map[ytetra][xtetra] == '*')
			{
				if (y + ytetra < 0 || x + xtetra < 0 \
				|| (y + ytetra >= map->height) || (x + xtetra >= map->width) \
				|| (map->heatmap[y + ytetra][x + xtetra] == ENEMY))
					return (-1);
				(map->heatmap[y + ytetra][x + xtetra] == PLAYER) ? player++ : 0;
				sum = sum + map->heatmap[y + ytetra][x + xtetra];
			}
		}
	}
	return ((player != 1) ? -1 : sum);
}

void			find_best_coords(t_filler *filler)
{
	int		x;
	int		y;
	int		sum;
	int		min_sum;

	min_sum = 2147483647;
	y = -(filler->tetra->miny) - 2;
	while (++y < filler->map->height - filler->tetra->maxy)
	{
		x = -(filler->tetra->minx) - 2;
		while (++x < filler->map->width - filler->tetra->maxx)
		{
			sum = find_sum(y, x, filler->tetra, filler->map);
			if (min_sum > sum && sum != -1)
			{
				min_sum = sum;
				filler->bestx = x;
				filler->besty = y;
			}
		}
	}
}
