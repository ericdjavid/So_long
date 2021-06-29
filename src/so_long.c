/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 11:32:40 by edjavid           #+#    #+#             */
/*   Updated: 2021/06/27 12:27:41 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void 	check_arg(int argc, char** argv)
{
	if (argc != 2)
	{
		ft_putendl_fd("invalid number of argument", 2);
		exit(0);
	}
	if ((ft_strlen(argv[1]) < 4) || (!ft_strrchr(argv[1],'.')))
	{
		ft_putendl_fd("invalid argument", 2);
		exit(0);
	}
	if (ft_strcmp(ft_strrchr(argv[1], '.'), ".ber") != 0)
	{
		ft_putendl_fd("file must be of type \"<name>.ber\"", 2);
		exit(0);
	}
}

int	key_hook(int keycode, t_game *game)
{
	printf("%d - Hello from key_hook!\n", keycode);
	if (keycode == 65307)
		mlx_destroy_window(game->mlx.mlx, game->mlx.mlx_win);
}

int 	init_map(t_game *game, char *map_name)
{
	FILE	*ptr;
	int 	count;
	char 	*map;
	char 	buf[1024 + 1]; // recheck pk

	ptr = open_s(map_name, r);
	if (ptr == NULL)
	{
		ft_putendl_fd("file cannot be read", 2)
		exit (0);
	}
	map =


}

int 	init_struc(t_game *game)
{
	game->numb_move = 0;
	game->map_height = 0;
	game->map_width = 0;
	game->mlx.mlx = mlx_init();
	game->mlx.mlx_win = mlx_new_window(game->mlx.mlx, 600, 400, "SO_LONG_EDJ");
}

int 	main (int argc, char** argv)
{
	t_game game;

	check_arg(argc, argv);
	init_struc(&game);

	//printf("num move value is %d", game.numb_move);
	mlx_key_hook(game.mlx.mlx_win, key_hook, &game);
	mlx_loop(game.mlx.mlx);

	//don't forget to free when game is finished
}