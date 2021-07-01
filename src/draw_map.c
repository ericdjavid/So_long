/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 12:45:11 by edjavid           #+#    #+#             */
/*   Updated: 2021/07/01 12:45:12 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"


void	check_for_elements(t_game *game, int x, int y, int numb)
{
	if (game->map[x + numb] == 'P')
	{
		draw_square(game, game->player, x * 40, y * 40);
	}
	if (game->map[x + numb] == 'C')
		draw_square(game, game->collectible, x * 40, y * 40);
	if (game->map[x + numb] == 'E')
		draw_square(game, game->exit, x * 40, y * 40);
}

void 	draw_square(t_game *game, t_img *img, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;

	j = 0;
	while (j < 40)
	{
		i = 0;
		while (i < 40)
		{
			color = mlx_get_pixel(img, i, j);
			if (color != mlx_rgb_to_int(0, 255, 255, 255))
				mlx_draw_pixel(game->mlx.mlx_img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

void	draw_map(t_game *game)
{
	int	x;
	int y;
	int numb;

	y = 0;
	numb = 0;

	game->mlx.mlx_img = mlx_new_image(game->mlx.mlx, game->map_width * 40, game->map_height * 40);
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (game->map[x + numb] == '1')
				draw_square(game, game->tree, x * 40, y * 40);
			else
			{
				draw_square(game, game->ground, x * 40, y * 40);
				check_for_elements(game, x, y, numb);
			}
			x++;
		}
		y++;
		numb = game->total_line_char * y;
		game->player_position = x + numb;
	}

	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->mlx.mlx_img, 0, 0);
}