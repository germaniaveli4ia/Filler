/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkapolly <alkapolly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 14:50:36 by alkapolly         #+#    #+#             */
/*   Updated: 2020/11/28 21:32:08 by alkapolly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_filler	*filler;

	filler = NULL;
	if (!(filler = init_filler()) || !(parse_filler(filler)) \
	|| !(init_map(filler)) || !(parse_map_size(filler)) || !(init_hmap(filler)))
		clean_and_exit(&filler);
	while (fill_heatmap(filler) && init_tetra(filler) \
	&& fill_tetra(filler, filler->tetra))
	{
		calc_heatmap(filler);
		find_best_coords(filler);
		ft_putnbr(filler->besty);
		ft_putchar(32);
		ft_putnbr(filler->bestx);
		ft_putchar('\n');
		free_tetra(&(filler->tetra));
		filler->bestx = 0;
		filler->besty = 0;
	}
	clean_and_exit(&(filler));
	free(filler);
	return (1);
}
