/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkapolly <alkapolly@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 14:58:11 by alkapolly         #+#    #+#             */
/*   Updated: 2020/11/28 21:39:36 by alkapolly        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include "libft.h"
# include "../minilibx_macos/includes/mlx.h"

# define EMPTY 0
# define PLAYER -1
# define ENEMY -2
# define WIDTH 1000
# define HEIGHT 1000
# define FONT 0xE3CB19
# define FD0 0

typedef struct		s_point
{
	int		x;
	int		y;
}					t_point;

typedef struct		s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*data_addr;
	char		**map;
	char		player;
	char		enemy;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			win_y;
	int			win_x;
	int			zoom;
	int			norm_x;
	int			norm_y;
	int			pause;
	int			height;
	int			width;
	int			enemy_score;
	int			my_score;
}					t_mlx;

int					main(void);

/*
** init
*/

t_mlx				*init_mlx(void);

/*
** parse and fill
*/

int					parse_basic_info(t_mlx *filler);
void				parse_map_size(t_mlx *filler, char *line);
int					parse_map(t_mlx *filler);

/*
** free
*/

void				clean_and_exit(t_mlx **filler);
void				free_map(char ***map);

/*
** draw
*/

void				draw_back(t_mlx *mlx);
void				draw_tetra(t_mlx *mlx, char **map);
int					draw_tetra2(t_mlx *mlx);
void				draw_cell(t_point strt, int y, int x, t_mlx *filler);
void				draw_score(t_mlx *mlx);
void				draw_result(t_mlx *mlx);

/*
** utils
*/

int					ft_mod(int a);
int					ft_min(int a, int b);
t_point				make_pnt(int y, int x, t_mlx *filler);

#endif
