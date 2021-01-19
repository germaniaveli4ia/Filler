/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkapolly <alkapolly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:31:44 by alkapolly         #+#    #+#             */
/*   Updated: 2020/11/28 21:41:07 by alkapolly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

t_mlx		*init_mlx(void)
{
	t_mlx	*mlx;

	if (!(mlx = ft_memalloc(sizeof(t_mlx))))
		return (NULL);
	mlx->win_y = HEIGHT;
	mlx->win_x = WIDTH;
	mlx->zoom = 0;
	mlx->norm_x = 0;
	mlx->norm_y = 0;
	mlx->bits_per_pixel /= 8;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, \
	mlx->win_x, mlx->win_y, "Filler by wmarya");
	mlx->img = mlx_new_image(mlx->mlx_ptr, mlx->win_x, mlx->win_y);
	mlx->data_addr = mlx_get_data_addr(mlx->img, \
	&(mlx->bits_per_pixel), &(mlx->size_line), &(mlx->endian));
	mlx->map = NULL;
	mlx->height = 0;
	mlx->width = 0;
	mlx->player = 0;
	mlx->enemy = 0;
	mlx->enemy_score = 0;
	mlx->my_score = 0;
	return (mlx);
}
