/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkapolly <alkapolly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 22:15:51 by alkapolly         #+#    #+#             */
/*   Updated: 2020/11/28 23:15:07 by alkapolly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void	put_pixel(t_mlx *filler, int x, int y, int color)
{
	int		i;

	if (x < 0 || x >= filler->win_x || y < 0 || y >= filler->win_y)
		return ;
	i = x * filler->bits_per_pixel / 8 + y * filler->size_line;
	filler->data_addr[i] = color;
	filler->data_addr[++i] = color >> 8;
	filler->data_addr[++i] = color >> 16;
}

void	ft_draw_line(t_point strt, t_point end, t_mlx *filler)
{
	int		x_step;
	int		y_step;
	int		max;

	x_step = end.x - strt.x;
	y_step = end.y - strt.y;
	max = ft_max(ft_mod(x_step), ft_mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((strt.x - end.x) || (strt.y - end.y))
	{
		put_pixel(filler, strt.x, strt.y, 0x000000);
		strt.x += x_step;
		strt.y += y_step;
	}
}

void	draw_back(t_mlx *mlx)
{
	int		x;
	int		y;

	y = -1;
	while (++y <= mlx->height)
	{
		x = -1;
		while (++x <= mlx->width)
		{
			if (x < mlx->width)
				ft_draw_line((make_pnt(y, x, mlx)), (make_pnt(y, x + 1, mlx)), \
				mlx);
			if (y < mlx->height)
				ft_draw_line((make_pnt(y, x, mlx)), (make_pnt(y + 1, x, mlx)), \
				mlx);
		}
	}
	draw_tetra(mlx, mlx->map);
}

void	draw_cell(t_point strt, int y, int x, t_mlx *filler)
{
	t_point	p2;
	t_point	p3;
	int		i;
	int		j;
	int		color;

	p2 = make_pnt(y, x + 1, filler);
	p3 = make_pnt(y + 1, x, filler);
	i = 0;
	if ((ft_toupper(filler->map[y][x]) == filler->player))
		color = 0x0F6F8B;
	else if ((ft_toupper(filler->map[y][x]) == filler->enemy))
		color = 0x4B0082;
	else
		color = 0xFFFFFF;
	while (++i < (p3.y - strt.y))
	{
		j = 0;
		while (++j < (p2.x - strt.x))
			put_pixel(filler, strt.x + j, strt.y + i, color);
	}
}

void	draw_tetra(t_mlx *mlx, char **map)
{
	int		x;
	int		y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (x < mlx->width && y < mlx->height)
			{
				if (map[y][x] == 'X' || map[y][x] == 'O')
				{
					draw_cell(make_pnt(y, x, mlx), y, x, mlx);
				}
			}
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, \
	mlx->norm_x, mlx->norm_y);
}
