/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wmarya <wmarya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 00:10:29 by alkapolly         #+#    #+#             */
/*   Updated: 2020/11/28 13:35:06 by wmarya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		parse_filler(t_filler *filler)
{
	char	*line;

	if (get_next_line(FD0, &line) < 1)
		return (0);
	if (ft_strstr(line, "p1"))
	{
		filler->player = 'O';
		filler->enemy = 'X';
	}
	else if (ft_strstr(line, "p2"))
	{
		filler->player = 'X';
		filler->enemy = 'O';
	}
	ft_strdel(&line);
	return (1);
}

int		parse_map_size(t_filler *filler)
{
	int		i;
	char	*line;

	i = 0;
	if (get_next_line(FD0, &line) < 1)
		return (0);
	while (!ft_isdigit(line[i]) && line[i])
		i++;
	filler->map->height = ft_atoi(line + i);
	while (line[i] != ' ' && line[i])
		i++;
	while (!ft_isdigit(line[i]) && line[i])
		i++;
	filler->map->width = ft_atoi(line + i);
	ft_strdel(&line);
	if (!filler->map->width || !filler->map->height)
		return (0);
	return (1);
}

int		parse_tetra_size(t_filler *filler)
{
	int		i;
	char	*line;

	i = 0;
	if (get_next_line(FD0, &line) < 1)
		return (0);
	while (!ft_isdigit(line[i]) && line[i])
		i++;
	filler->tetra->height = ft_atoi(line + i);
	while (line[i] != ' ' && line[i])
		i++;
	while (!ft_isdigit(line[i]) && line[i])
		i++;
	filler->tetra->width = ft_atoi(line + i);
	ft_strdel(&line);
	if (!filler->map->width || !filler->map->height)
		return (0);
	return (1);
}

int		skip_misc(t_filler *filler)
{
	char	*line;

	if ((get_next_line(FD0, &line) < 1))
	{
		free(line);
		return (0);
	}
	if (ft_strstr(line, "Plateau"))
	{
		ft_strdel(&line);
		get_next_line(FD0, &line);
	}
	if ((int)ft_strlen(line) < filler->map->width + 4)
	{
		if (line)
			ft_strdel(&line);
		return (0);
	}
	ft_strdel(&line);
	return (1);
}
