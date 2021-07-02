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
	//TODO problem when 2 exits
	if (ft_strchr(game->map, 'C') == NULL)
		while (ft_strchr(game->map, 'E'))
			*ft_strchr(game->map, 'E') = 'X';
	if (keycode == 65307)
		mlx_destroy_window(game->mlx.mlx, game->mlx.mlx_win);

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
	if (ft_strchr(game->map, 'X') == NULL && ft_strchr(game->map, 'E') == NULL)
		exit(1);
	draw_map(game);

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


	while (ret > 0)
	{
		count++;
		int endline = ft_strlen(line) - 1;
		if (line[0] != '1' || line[endline] != '1')
		{
			ft_putendl_fd("Wall missing in the border", 2);
			exit (0);
		}
		whole_chars = ft_strjoin(whole_chars, line);

		free(line);
		line = 0;
		ret = get_next_line(fd, &line);
		ft_strjoin(whole_chars, line);
		if ((strlen(line)) != first_line_char_sum)
		{
			ft_putendl_fd("map is not rectangular", 2);
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
	if ((ft_strchr(whole_chars, 'P') == NULL) || (ft_strchr(whole_chars, 'E') == NULL) ||
	(ft_strchr(whole_chars, 'C') == NULL))
	{
		ft_putendl_fd("Missing one player, one collectible or one exit", 2);
		exit (0);
	}
	game->map_height = count * 40;
	game->map_width = first_line_char_sum * 40;
	game->map = whole_chars;
	game->total_line_char = first_line_char_sum;
	game->line_number = count;
	fd = close(fd);
}

int 	init_struc(t_game *game)
{
	game->numb_move = 0;
	game->collected = 0;
	game->mlx.mlx = mlx_init();
	game->mlx.mlx_win = mlx_new_window(game->mlx.mlx, game->map_width, game->map_height, "SO_LONG_EDJ");
	game->mlx.mlx_img = mlx_new_image(game->mlx.mlx, game->map_width, game->map_height);
	texture_init(game);
}

//TODO exit when clicking on the top-right border cross
//TODO count number of move
//TODO adapt code to norm V3
//TODO check leaks with valgrind
int 	main (int argc, char** argv)
{
	t_game game;

	check_arg(argc, argv);
	init_map(&game, argv[1]);
	init_struc(&game);
	draw_map(&game);
	mlx_key_hook(game.mlx.mlx_win, key_hook, &game);
	mlx_loop(game.mlx.mlx);

	//don't forget to free when game is finished
}