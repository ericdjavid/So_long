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
#include "../inc/get_next_line.h"

void	texture_load(t_game *game, t_img **img, char *path)
{
	int				width;
	int				height;

	*img = mlx_xpm_file_to_image(game->mlx.mlx, path, &width, &height);
	if (*img == 0)
		ft_putendl_fd("Error\nCan't load texture", 2);
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

void	check_arg(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl_fd("Error\nInvalid number of argument", 2);
		exit(0);
	}
	if ((ft_strlen(argv[1]) < 4) || (!ft_strrchr(argv[1], '.')))
	{
		ft_putendl_fd("Error\ninvalid argument", 2);
		exit(0);
	}
	if (ft_strcmp(ft_strrchr(argv[1], '.'), ".ber") != 0)
	{
		ft_putendl_fd("Error\nfile must be of type \"<name>.ber\"", 2);
		exit(0);
	}
}

int	init_map(t_game *game, char *map_name)
{
	int	fd;
	char	*line;
	int	ret;
	int	count;
	int	first_line_char_sum;
	char	*whole_chars;
	int	endline;

	whole_chars = malloc(sizeof(char) * 10000);
	*whole_chars = 0;
	count = 0;
	fd = open(map_name, O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error\nfile cannot be read", 2);
		free(whole_chars);
		exit (0);
	}
	line = 0;
	ret = get_next_line(fd, &line);
	check_walls(line);
	first_line_char_sum = strlen(line);
	while (ret > 0)
	{
		count++;
		endline = ft_strlen(line) - 1;
		if (line[0] != '1' || line[endline] != '1')
		{
			ft_putendl_fd("Error\nWall missing in the border", 2);
			free(whole_chars);
			exit (0);
		}
		ft_strcat(whole_chars, line);
		free(line);
		line = 0;
		ret = get_next_line(fd, &line);
		if ((strlen(line)) != (long unsigned int)first_line_char_sum)
		{
			ft_putendl_fd("Error\nmap is not rectangular", 2);
			free(whole_chars);
			exit (0);
		}
		if (ret == 0)
		{
			count++;
			check_walls(line);
			ft_strcat(whole_chars, line);
			free(line);
			line = 0;
		}
	}
	if ((ft_strchr(whole_chars, 'P') == NULL)
		|| (ft_strchr(whole_chars, 'E') == NULL)
		|| (ft_strchr(whole_chars, 'C') == NULL))
	{
		ft_putendl_fd
		("Error\nMissing one player, one collectible or one exit", 2);
		free(whole_chars);
		exit (0);
	}
	check_map_elements(whole_chars);
	game->map_height = count * 40;
	game->map_width = first_line_char_sum * 40;
	game->map = malloc(sizeof(char) * (first_line_char_sum * count) + 1);
	ft_strlcpy(game->map, whole_chars, (count * first_line_char_sum));
	game->total_line_char = first_line_char_sum;
	game->line_number = count;
	fd = close(fd);
	free(whole_chars);
	return (1);
}

int	init_struc(t_game *game)
{
	game->nb_exit = 0;
	game->numb_move = 1;
	game->mlx.mlx = mlx_init();
	game->mlx.mlx_win = mlx_new_window(game->mlx.mlx,
			game->map_width, game->map_height, "SO_LONG_EDJ");
	game->mlx.mlx_img = mlx_new_image
		(game->mlx.mlx, game->map_width, game->map_height);
	texture_init(game);
	return (1);
}

int	reduce_window(t_game *game)
{
	draw_map(game);
	return (1);
}

//TODO adapt code to norm V3
int	main(int argc, char **argv)
{
	t_game	game;

	check_arg(argc, argv);
	init_map(&game, argv[1]);
	init_struc(&game);
	draw_map(&game);
	mlx_key_hook(game.mlx.mlx_win, key_hook, &game);
	mlx_hook(game.mlx.mlx_win, 33, 1L << 5, exit_hook, &game);
	mlx_hook(game.mlx.mlx_win, 15, 1L << 16, reduce_window, &game);
	mlx_loop(game.mlx.mlx);
}
