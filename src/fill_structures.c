/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkapolly <alkapolly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 20:10:47 by alkapolly         #+#    #+#             */
/*   Updated: 2020/11/28 21:18:45 by alkapolly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		fill_heatmap2(int *heatmap, char *line, int width, \
t_filler *filler)
{
	int		x;

	x = -1;
	while (++x < width)
	{
		if ((line[x + 4] != '.' && line[x + 4] != 'x' && line[x + 4] != 'o'
		&& line[x + 4] != 'O' && line[x + 4] != 'X') || line[x + 4] == '\0')
			return (0);
		if (line[x + 4] == '.')
		{
			heatmap[x] = EMPTY;
		}
		else if (ft_toupper(line[x + 4]) == filler->player)
		{
			heatmap[x] = PLAYER;
		}
		else if (ft_toupper(line[x + 4]) == filler->enemy)
		{
			heatmap[x] = ENEMY;
		}
	}
	return (1);
}

int				fill_heatmap(t_filler *filler)
{
	char	*line;
	int		y;

	if (!skip_misc(filler))
		return (0);
	y = -1;
	while (++y < filler->map->height)
	{
		if ((get_next_line(FD0, &line)) < 1)
			return (0);
		if (!(fill_heatmap2(filler->map->heatmap[y], line, filler->map->width, \
		filler)))
		{
			ft_strdel(&line);
			return (0);
		}
		ft_strdel(&line);
	}
	return (1);
}

static int		check_forbidden(t_tetra *tetra, char *line, int y)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '*' || line[i] == '.')
		{
			if (line[i] == '*')
			{
				tetra->minx = (tetra->minx > i) ? i : tetra->minx;
				tetra->miny = (tetra->miny > y) ? y : tetra->miny;
				tetra->maxx = (tetra->maxx < i) ? i : tetra->maxx;
				tetra->maxy = (tetra->maxy > y) ? y : tetra->maxy;
			}
			i++;
		}
		else
			return (0);
	}
	if (i != tetra->width)
		return (0);
	return (1);
}

int				fill_tetra(t_filler *filler, t_tetra *tetra)
{
	int		y;

	if (!parse_tetra_size(filler)
	|| !(tetra->map = (char **)ft_memalloc(sizeof(char *) * tetra->height)))
		return (0);
	y = -1;
	while (++y < filler->tetra->height)
	{
		if ((get_next_line(FD0, &(tetra->map[y]))) != 1
		|| !check_forbidden(filler->tetra, filler->tetra->map[y], y))
			return (0);
	}
	return (1);
}
