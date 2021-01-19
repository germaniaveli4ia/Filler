/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkapolly <alkapolly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 19:42:49 by wmarya            #+#    #+#             */
/*   Updated: 2020/11/29 20:30:29 by alkapolly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int		ft_mod(int a)
{
	return (a < 0 ? a * -1 : a);
}

int		ft_min(int a, int b)
{
	return (a < b ? a : b);
}

t_point	make_pnt(int y, int x, t_mlx *filler)
{
	t_point	point;

	point.y = y * filler->zoom;
	point.x = x * filler->zoom;
	return (point);
}

void	draw_score(t_mlx *mlx)
{
	char	*score;

	score = "wmarya.filler:";
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, mlx->norm_x + 10, \
	mlx->norm_y + 10, FONT, score);
	if (!(score = ft_itoa(mlx->my_score)))
		clean_and_exit(&mlx);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, mlx->norm_x + 10, \
	mlx->norm_y + 30, FONT, score);
	ft_strdel(&score);
	score = "enemy.filler:";
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, mlx->norm_x + 10, \
	mlx->norm_y + 50, FONT, score);
	if (!(score = ft_itoa(mlx->enemy_score)))
		clean_and_exit(&mlx);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, mlx->norm_x + 10, \
	mlx->norm_y + 70, FONT, score);
	ft_strdel(&score);
}

void	draw_result(t_mlx *mlx)
{
	char	*score;
	int		x;
	int		y;

	x = mlx->norm_x + (mlx->width * mlx->zoom / 2) - 30;
	y = mlx->norm_y + (mlx->height * mlx->zoom / 2) - 20;
	if (mlx->my_score > mlx->enemy_score)
	{
		score = "YOU WON!";
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0xE14C45, score);
	}
	else if (mlx->my_score < mlx->enemy_score)
	{
		score = "TRY AGAIN ;)";
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0xE14C45, score);
	}
	else
	{
		score = "OOPS! It's a draw!";
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, x, y, 0xE14C45, score);
	}
}
