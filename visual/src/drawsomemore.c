/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawsomemore.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkapolly <alkapolly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 22:15:51 by alkapolly         #+#    #+#             */
/*   Updated: 2020/11/28 22:31:57 by alkapolly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

static int	skip_misc(void)
{
	int		ret;
	char	*line;

	ret = 0;
	while ((ret = get_next_line(FD0, &line)) == 1 && !ft_strstr(line, "01234"))
		ft_strdel(&line);
	ft_strdel(&line);
	if (ret <= 0)
		return (0);
	return (1);
}

static void	calc_score(char c, t_mlx *mlx, int *flag)
{
	if (ft_toupper(c) == mlx->enemy)
		mlx->enemy_score++;
	else
		mlx->my_score++;
	*flag = 1;
}

void		find_tetra(int y, char *line, t_mlx *mlx, int *flag)
{
	int		x;

	x = -1;
	while (line[++x + 4])
	{
		if (x < mlx->width && y < mlx->height)
		{
			if (line[x + 4] == 'x' || line[x + 4] == 'o')
			{
				mlx->map[y][x] = line[x + 4];
				draw_cell(make_pnt(y, x, mlx), y, x, mlx);
				if (*flag == 0)
					calc_score(line[x + 4], mlx, flag);
			}
		}
	}
}

int			draw_tetra2(t_mlx *mlx)
{
	int		y;
	char	*line;
	int		flag;

	flag = 0;
	if (!skip_misc())
		return (0);
	y = -1;
	while (get_next_line(FD0, &line) == 1 && ++y < mlx->height)
	{
		find_tetra(y, line, mlx, &flag);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, \
	mlx->norm_x, mlx->norm_y);
	return (1);
}
