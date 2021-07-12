/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 10:46:16 by edjavid           #+#    #+#             */
/*   Updated: 2021/06/30 10:46:20 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	problems(char *nature, char *whole_chars)
{
	ft_putendl_fd(nature, 2);
	free(whole_chars);
	exit (0);
}

void	check_walls(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
		{
			ft_putendl_fd("map is not surrounded by walls", 2);
			free(line);
			exit (1);
		}
		i++;
	}
}

void	check_map_elements(char *whole_chars)
{
	int	i;
	int	count_p;

	i = 0;
	count_p = 0;
	while (whole_chars[i] != '\0')
	{
		if (whole_chars[i] == 'P')
			count_p++;
		if ((whole_chars[i] != '1') && (whole_chars[i] != '0')
			&& (whole_chars[i] != 'E') && (whole_chars[i] != 'P')
			&& (whole_chars[i] != 'C'))
		{
			ft_putendl_fd
			("Error\nFile contains different character than 1, 0, P, E or C", 2);
			free(whole_chars);
			exit (1);
		}
		i++;
	}
	if (count_p > 1)
		problems("only one player should be on the map", whole_chars);
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
