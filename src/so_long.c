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

void	init_map2(t_game *game, char *whole_chars)
{
	if ((ft_strchr(whole_chars, 'P') == NULL)
		|| (ft_strchr(whole_chars, 'E') == NULL)
		|| (ft_strchr(whole_chars, 'C') == NULL))
		problems("Error\nMissing one player, one collectible or one exit",
			whole_chars);
	if (game->line_number - 1 == game->total_line_char)
		problems("Error\nMap is square!", whole_chars);
	check_map_elements(whole_chars);
	game->map_height = (game->line_number - 1) * 40;
	game->map_width = game->total_line_char * 40;
	game->map = malloc(sizeof(char)
			* (game->total_line_char * game->line_number) + 1);
	ft_strlcpy(game->map, whole_chars,
		(game->line_number * game->total_line_char));
	game->fd = close(game->fd);
	free(whole_chars);
}

void	deal_ret(int ret, t_game *game, char *line, char *whole_chars)
{
	while (ret > 0)
	{
		game->line_number++;
		game->endline = ft_strlen(line) - 1;
		if (line[0] != '1' || line[game->endline] != '1')
			problems("Error\nWall missing in the border", whole_chars);
		ft_strcat(whole_chars, line);
		free(line);
		line = 0;
		ret = get_next_line(game->fd, &line);
		if ((ret != 0) && (strlen(line)
				!= (long unsigned int)game->total_line_char))
			problems("Error\nmap has a problem", whole_chars);
		if (ret == 0)
		{
			game->line_number++;
			check_walls(line);
			ft_strcat(whole_chars, line);
			free(line);
			line = 0;
		}
	}
}

int	init_map(t_game *game, char *map_name)
{
	char	*line;
	int		ret;
	char	*whole_chars;

	whole_chars = malloc(sizeof(char) * 10000);
	*whole_chars = 0;
	game->line_number = 0;
	game->fd = open(map_name, O_RDONLY);
	if (game->fd == -1)
		problems("Error\nfile cannot be read", whole_chars);
	line = 0;
	ret = get_next_line(game->fd, &line);
	check_walls(line);
	game->total_line_char = strlen(line);
	deal_ret(ret, game, line, whole_chars);
	init_map2(game, whole_chars);
	return (1);
}

int	init_struc(t_game *game)
{
	game->nb_exit = 0;
	game->numb_move = 0;
	game->mlx.mlx = mlx_init();
	game->mlx.mlx_win = mlx_new_window(game->mlx.mlx,
			game->map_width, game->map_height, "SO_LONG_EDJ");
	game->mlx.mlx_img = mlx_new_image
		(game->mlx.mlx, game->map_width, game->map_height);
	texture_init(game);
	return (1);
}

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
