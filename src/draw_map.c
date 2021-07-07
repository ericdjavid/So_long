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

void	check_for_elements(t_game *game, int x, int y, int z, int numb)
{
	if (game->map[z + numb] == 'P')
		draw_square(game, game->player, x, y * 40);
	if (game->map[z + numb] == 'C')
		draw_square(game, game->collectible, x, y * 40);
	if (game->map[z + numb] == 'E' || game->map[z + numb] == 'X')
		draw_square(game, game->exit, x, y * 40);
}


void	draw_map(t_game *game)
{
	int	x;
	int y;
	int numb;
	int z;

	numb = 0;
	y = 0;
	x = -40;
	while(y < game->line_number)
	{
		z = 0;
		while (z < (game->total_line_char))
		{
			if (game->map[z + numb] == '1')
				draw_square(game, game->tree, x += 40, y * 39);
			else
			{
				draw_square(game, game->ground, x += 40, y * 39);
				check_for_elements(game, x, y, z, numb);
			}
		z++;
		}
		y++;
		numb = game->total_line_char * y;
	}
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win, game->mlx.mlx_img, 0, 0);
}