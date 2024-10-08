/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungcho <hyungcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:29:45 by hyungcho          #+#    #+#             */
/*   Updated: 2024/10/07 21:52:23 by hyungcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"
#include "include/graphic.h"

#include <stdio.h>

int	exit_game(void)
{
	exit(0);
}

void	draw(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->win_height)
	{
		x = -1;
		if (y < game->win_height / 2)
			while (++x < game->win_width)
				mlx_pixel_put(game->mlx, game->win, x, y, game->ceiling_color);
		else
			while (++x < game->win_width)
				mlx_pixel_put(game->mlx, game->win, x, y, game->floor_color);
	}
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == ESC)
		exit_game();
	(void) game;
	return (0);
}

void	start_grapic(t_data *data, t_img_path *img_path)
{
	t_game	game;

	game = init_game(data, *img_path);
	draw(&game);
	mlx_hook(game.win, KEY_PRESS, 0, key_press, &game);
	mlx_hook(game.win, DESTROY_NOTIFY, 0, exit_game, 0);
	mlx_loop(game.mlx);
}
