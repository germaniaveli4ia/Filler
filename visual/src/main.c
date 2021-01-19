/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkapolly <alkapolly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 14:50:36 by alkapolly         #+#    #+#             */
/*   Updated: 2020/11/28 23:29:05 by alkapolly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

int		ft_bind_key(int key, t_mlx *data)
{
	if (key == 53)
	{
		clean_and_exit(&data);
	}
	return (0);
}

int		loop_hook(t_mlx *filler)
{
	int		ret;

	if ((ret = draw_tetra2(filler)) > 0)
	{
		mlx_hook(filler->win_ptr, 2, 0, ft_bind_key, filler);
		draw_score(filler);
		mlx_do_sync(filler->mlx_ptr);
	}
	else
	{
		draw_result(filler);
		return (0);
	}
	return (1);
}

int		main(void)
{
	t_mlx	*filler;

	filler = NULL;
	if (!(filler = init_mlx()))
		clean_and_exit(&filler);
	parse_basic_info(filler);
	draw_back(filler);
	mlx_hook(filler->win_ptr, 2, 0, ft_bind_key, filler);
	mlx_loop_hook(filler->mlx_ptr, loop_hook, filler);
	mlx_loop(filler->mlx_ptr);
	clean_and_exit(&(filler));
	return (1);
}
