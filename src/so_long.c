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
	int 	fd;
	char	*line;
	int 	ret;
	int 	count;
	char 	*map;

	count = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("file cannot be read", 2);
		exit (0);
	}
	line = 0;
	ret = get_next_line(fd, &line);

	//si count = 0, all characters must be 1
	//if last line, all characters must be 1
	//if nb character different par line, ko
	//if no E or P, ko
	while (ret > 0)
	{
		count++;
		int endline = ft_strlen(line) - 2;

		if (line[0] != '1' || line[endline] != '1')
		{

			printf("\nerror in line %d on character number %d\n", count, endline + 1);
			exit (0);
		}
		write(1, line, ft_strlen(line));

		write(1, "\n", 1);
		free(line);
		line = 0;
		ret = get_next_line(fd, &line);
	}
	if (ret == 0)
	{
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
		free(line);
		line = 0;
	}
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
	init_map(&game, argv[1]);
	init_struc(&game);

	//printf("num move value is %d", game.numb_move);
	mlx_key_hook(game.mlx.mlx_win, key_hook, &game);
	mlx_loop(game.mlx.mlx);

	//don't forget to free when game is finished
}