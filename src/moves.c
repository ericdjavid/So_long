/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:31:34 by edjavid           #+#    #+#             */
/*   Updated: 2021/07/08 17:31:36 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void 	move_bottom(t_game *game)
{
	char *ptr;
	int i;

	ptr = strchr(game->map, 'P');
	i = -1;
	while (++i < game->total_line_char)
		++ptr;
	if (*ptr != '1' && *ptr != 'E')
	{
		*ptr = 'P';
		ptr = ft_strchr(game->map, 'P');
		*ptr = '0';
	}
	mlx_destroy_image(game->mlx.mlx, game->player);
	texture_load(game, &game->player, "./img/link1.xpm");
	game->numb_move += 1;
}

void 	move_up(t_game *game)
{
	char *ptr = ft_strchr(game->map, 'P');
	int i = -1;
	while (++i < game->total_line_char)
		--ptr;
	if (*ptr != '1' && *ptr != 'E')
	{
		*ptr = 'P';
		while (--i >= 0)
			++ptr;
		*ptr = '0';
	}
	mlx_destroy_image(game->mlx.mlx, game->player);
	texture_load(game, &game->player, "./img/link_up.xpm");
	game->numb_move += 1;
}

void 	move_right(t_game *game)
{
	char *ptr = ft_strchr(game->map, 'P');
	if ((*++ptr != '1' && *ptr != 'E'))
	{
		*--ptr = '0';
		*++ptr = 'P';
	}
	mlx_destroy_image(game->mlx.mlx, game->player);
	texture_load(game, &game->player, "./img/link_right.xpm");
	game->numb_move += 1;
}

void 	move_left(t_game *game)
{
	char *ptr = ft_strchr(game->map, 'P');
	if (*--ptr != '1' && *ptr != 'E')
	{
		*++ptr = '0';
		*--ptr = 'P';
	}
	mlx_destroy_image(game->mlx.mlx, game->player);
	texture_load(game, &game->player, "./img/link_left.xpm");
	game->numb_move += 1;
}