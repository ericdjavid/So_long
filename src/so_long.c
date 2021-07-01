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


static void	texture_load(t_game *game, t_img **img, char *path)
{
	int				width;
	int				height;

	*img = mlx_xpm_file_to_image(game->mlx.mlx, path, &width, &height);
	if (*img == 0)
		ft_putendl_fd("texture_init(): can't load texture", 2);
	(*img)->width = width;
	(*img)->height = height;
}

static void	texture_init(t_game *game)
{
	texture_load(game, &game->player, "./img/link1.xpm");
	texture_load(game, &game->exit, "./img/tent.xpm");
	texture_load(game, &game->collectible, "./img/key.xpm");
	texture_load(game, &game->tree, "./img/tree.xpm");
	texture_load(game, &game->ground, "./img/ground.xpm");
}

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

int		key_hook(int keycode, t_game *game)
{
	printf("%d - Hello from key_hook!\n", keycode);
	if (keycode == 65307)
		mlx_destroy_window(game->mlx.mlx, game->mlx.mlx_win);
	if (keycode == 119)
	{
		game->map[game->player_position] = '0';

	//	game->map[game->player_position + game->total_line_char] = 'P';
		draw_map(game);

	//	printf("\n player position y is %d\n", game->player_position_y);

	}

}

int 	init_map(t_game *game, char *map_name)
{
	int 	fd;
	char	*line;
	char 	*whole_chars;
	int 	ret;
	int 	count;
	char 	*map;
	int 	first_line_char_sum;

	whole_chars = ft_calloc(1, 1);
	count = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("file cannot be read", 2);
		exit (0);
	}
	line = 0;
	ret = get_next_line(fd, &line);
	checkwalls(line);
	first_line_char_sum = strlen(line);

	//TODO if no E or P, ko
	while (ret > 0)
	{
		count++;
		int endline = ft_strlen(line) - 1;
		if (line[0] != '1' || line[endline] != '1')
		{
			printf("\nerror in line %d on character number %d\n", count, endline + 1);
			exit (0);
		}
		whole_chars = ft_strjoin(whole_chars, line);
		write(1, line, ft_strlen(line));
		write(1, "\n", 1);
		free(line);
		line = 0;
		ret = get_next_line(fd, &line);
		ft_strjoin(whole_chars, line);
		if ((strlen(line)) != first_line_char_sum)
		{
			printf("ret is %d , map is not rectangular, line is %d and first line is %d", ret, ft_strlen(line), first_line_char_sum);
			exit (0);
		}
		if (ret == 0)
		{
			count++;
			checkwalls(line);
			whole_chars = ft_strjoin(whole_chars, line);
			write(1, line, ft_strlen(line));
			write(1, "\n", 1);
			free(line);
			line = 0;
		}
	}
	game->map_height = count * 40;
	game->map_width = first_line_char_sum * 40;
	game->map = whole_chars;
	game->total_line_char = first_line_char_sum;

	//TODO don't forget to close
}

int 	init_struc(t_game *game)
{
	game->numb_move = 0;
	game->mlx.mlx = mlx_init();
	game->mlx.mlx_win = mlx_new_window(game->mlx.mlx, game->map_width, game->map_height, "SO_LONG_EDJ");
	texture_init(game);
	draw_map(game);
}

//TODO moving player
//TODO collecting stuff
//TODO exit when exit
int 	main (int argc, char** argv)
{
	t_game game;

	check_arg(argc, argv);
	init_map(&game, argv[1]);
	init_struc(&game);
	mlx_key_hook(game.mlx.mlx_win, key_hook, &game);
	mlx_loop(game.mlx.mlx);

	//don't forget to free when game is finished
}