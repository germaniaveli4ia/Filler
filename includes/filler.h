/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkapolly <alkapolly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 14:58:11 by alkapolly         #+#    #+#             */
/*   Updated: 2020/11/28 21:37:24 by alkapolly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

# define EMPTY 0
# define PLAYER -1
# define ENEMY -2
# define FD0 0

typedef struct		s_map
{
	int				height;
	int				width;
	int				**heatmap;
}					t_map;

typedef struct		s_tetra
{
	int				height;
	int				width;
	int				miny;
	int				minx;
	int				maxy;
	int				maxx;
	char			**map;
}					t_tetra;

typedef struct		s_filler
{
	t_map			*map;
	t_tetra			*tetra;
	char			enemy;
	char			player;
	int				bestx;
	int				besty;
}					t_filler;

int					main(void);

/*
** init
*/

t_filler			*init_filler(void);
int					init_map(t_filler *filler);
int					init_hmap(t_filler *filler);
int					init_tetra(t_filler *filler);

/*
** parse and fill
*/

int					parse_filler(t_filler *filler);
int					parse_map_size(t_filler *filler);
int					parse_tetra_size(t_filler *filler);
int					skip_misc(t_filler *filler);
int					fill_tetra(t_filler *filler, t_tetra *tetra);
int					fill_heatmap(t_filler *filler);

/*
** find best coords
*/

void				calc_heatmap(t_filler *filler);
void				find_best_coords(t_filler *filler);

/*
** free
*/

void				clean_and_exit(t_filler **filler);
void				free_tetramap(char ***tetramap);
void				free_map(int ***hmap);
void				free_tetra(t_tetra **tetra);

#endif
