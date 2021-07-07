/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:55:48 by edjavid           #+#    #+#             */
/*   Updated: 2021/07/06 15:55:49 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int		key_hook(int keycode, t_game *game)
{
	game->numb_move += 1;
	ft_putnbr_fd(game->numb_move, 1);
	ft_putchar_fd('\n', 1);
	if (ft_strchr(game->map, 'C') == NULL)
		while (ft_strchr(game->map, 'E'))
		{
			game->nb_exit++;
			*ft_strchr(game->map, 'E') = 'X';
		}
	if (keycode == 65307)
	{
		free(game->map);
		mlx_destroy_window(game->mlx.mlx, game->mlx.mlx_win);
		exit(1);
	}

	if (keycode == 119)
	{
		char *ptr = strchr(game->map, 'P');
		int i = -1;
		while (++i < game->total_line_char)
			++ptr;
		if (*ptr != '1' && *ptr != 'E')
		{
			*ptr = 'P';
			ptr = ft_strchr(game->map, 'P');
			*ptr = '0';
		}
		texture_load(game, &game->player, "./img/link1.xpm");
	}

	if (keycode == 97)
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
		texture_load(game, &game->player, "./img/link_up.xpm");
	}

	if (keycode == 100)
	{
		char *ptr = ft_strchr(game->map, 'P');
		if ((*++ptr != '1' && *ptr != 'E'))
		{
			*--ptr = '0';
			*++ptr = 'P';
		}
		texture_load(game, &game->player, "./img/link_right.xpm");
	}
	if (keycode == 115)
	{
		char *ptr = ft_strchr(game->map, 'P');
		if (*--ptr != '1' && *ptr != 'E')
		{
			*++ptr = '0';
			*--ptr = 'P';
		}
		texture_load(game, &game->player, "./img/link_left.xpm");
	}
	int count = 0;
	if (ft_strchr(game->map, 'E') == NULL)
	{
		if (game->nb_exit <= 1)
		{
			if(ft_strchr(game->map, 'X') == NULL)
			{
				free(game->map);
				exit(1);
			}
		}
		else
		{
			int i = 0;

			while (game->map[i])
			{	if (game->map[i] == 'X')
					count++;
				i++;
			}
			if (count == game->nb_exit - 1)
			{
				free(game->map);
				exit(1);
			}
		}
	}
	draw_map(game);
	return (1);
}

int		exit_hook(t_game *game)
{
	free(game->map);
	exit(1);
}