/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edjavid <ericdjavid@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 16:40:35 by edjavid           #+#    #+#             */
/*   Updated: 2021/06/27 12:26:31 by edjavid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_SO_LONG_H
#define __FT_SO_LONG_H

#include "libft.h"
#include <mlx.h>
#include <mlx_int.h>
#include <stdio.h>

typedef struct s_mlx
{
	void*	mlx_win;
	void*	mlx;

}	t_mlx;

typedef struct s_game
{
	t_mlx	mlx;
	int 	map_width;
	int 	map_height;
	int 	numb_move;
	t_img	ground;
	t_img	player;
	t_img	collectible;
	t_img	exit;

} t_game;

typedef struct s_coord
{
	int x;
	int y;
} t_coord;

#endif
