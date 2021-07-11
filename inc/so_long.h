/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 16:40:35 by edjavid           #+#    #+#             */
/*   Updated: 2021/06/27 12:26:31 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <stdio.h>

typedef struct s_mlx
{
	void	*mlx_win;
	void	*mlx;
	t_img	*mlx_img;

}	t_mlx;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_game
{
	t_mlx	mlx;
	int		map_width;
	int		map_height;
	int		numb_move;
	t_img	*ground;
	t_img	*player;
	t_img	*collectible;
	t_img	*tree;
	t_img	*exit;
	char	*map;
	int		total_line_char;
	int		line_number;
	char	*player_position;
	int		nb_exit;
	int		numb;
	int		endline;
	int		fd;
	int		x;
	int		y;
}	t_game;

void			texture_load(t_game *game, t_img **img, char *path);
void			check_arg(int argc, char **argv);
int				key_hook(int keycode, t_game *game);
void			check_walls(char *line);
void			check_map_elements(char *whole_chars);
int				init_struc(t_game *game);
int				init_map(t_game *game, char *map_name);
void			draw_map(t_game *game);
void			draw_square(t_game *game, t_img *img, int x, int y);
unsigned int	mlx_get_pixel(t_img *img, int x, int y);
void			mlx_draw_pixel(t_img *mlx_img, int x, int y, int color);
unsigned int	mlx_rgb_to_int(int o, int r, int g, int b);
void			check_for_elements(t_game *game, int x, int y, int z);
int				exit_hook(t_game *game);
void			move_bottom(t_game *game);
void			move_left(t_game *game);
void			move_right(t_game *game);
void			move_up(t_game *game);
void			is_game_finished(t_game *game);
void			texture_init(t_game *game);
int				reduce_window(t_game *game);
void			problems(char *nature, char *whole_chars);
#endif
