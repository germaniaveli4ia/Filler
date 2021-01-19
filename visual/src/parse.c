/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkapolly <alkapolly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 00:10:29 by alkapolly         #+#    #+#             */
/*   Updated: 2020/11/29 22:59:28 by alkapolly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int			parse_map(t_mlx *filler)
{
	char	*line;
	int		y;

	while (get_next_line(FD0, &line) == 1 && !ft_strstr(line, "01234"))
		ft_strdel(&line);
	ft_strdel(&line);
	y = -1;
	if (!(filler->map = ft_memalloc(sizeof(char *) * filler->height + 1)))
		return (0);
	while (++y < filler->height && get_next_line(FD0, &line) == 1)
	{
		filler->map[y] = ft_strdup(line + 4);
		ft_strdel(&line);
	}
	filler->map[y] = NULL;
	ft_strdel(&line);
	return (1);
}

void		parse_map_size(t_mlx *filler, char *line)
{
	int		i;

	i = 0;
	while (!ft_isdigit(line[i]) && line[i])
		i++;
	filler->height = ft_atoi(line + i);
	while (line[i] != ' ' && line[i])
		i++;
	while (!ft_isdigit(line[i]) && line[i])
		i++;
	filler->width = ft_atoi(line + i);
	filler->zoom = (ft_min(WIDTH / filler->width / 2,
	HEIGHT / filler->height / 2));
	filler->norm_x = (WIDTH - filler->width * filler->zoom) / 2;
	filler->norm_y = (HEIGHT - filler->height * filler->zoom) / 2;
}

int			parse_basic_info(t_mlx *filler)
{
	char	*line;

	while ((get_next_line(FD0, &line) == 1) \
	&& !ft_strstr(line, "/wmarya.filler]"))
		ft_strdel(&line);
	if (ft_strstr(line, "p1"))
	{
		filler->player = 'O';
		filler->enemy = 'X';
	}
	else
	{
		filler->player = 'X';
		filler->enemy = 'O';
	}
	ft_strdel(&line);
	while ((get_next_line(FD0, &line) == 1) && !ft_strstr(line, "Plateau"))
		ft_strdel(&line);
	parse_map_size(filler, line);
	ft_strdel(&line);
	if (!(parse_map(filler)))
		return (0);
	return (1);
}
