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

	i = 0;
	while (whole_chars[i] != '\0')
	{
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
}
