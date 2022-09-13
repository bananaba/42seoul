/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 22:38:59 by balee             #+#    #+#             */
/*   Updated: 2022/09/13 09:35:10 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	draw_component(t_game *game, int i, int j)
{
	if (game->map_info.map[i][j] == WALL)
	{
		if (((j * 3) + (i * 7)) % 11 != 0)
			mlx_put_image_to_window(game->mlx, game->win,
				game->tile_info.tile_wall_1.ptr, j * TILE, i * TILE);
		else
			mlx_put_image_to_window(game->mlx, game->win,
				game->tile_info.tile_wall_2.ptr, j * TILE, i * TILE);
	}
	else
	{
		if (((j * 13) + (i * 11)) % 5 == 0)
			mlx_put_image_to_window(game->mlx, game->win,
				game->tile_info.tile_grass_1.ptr, j * TILE, i * TILE);
		if (((j * 17) + (i * 7)) % 11 == 0)
			mlx_put_image_to_window(game->mlx, game->win,
				game->tile_info.tile_grass_2.ptr, j * TILE, i * TILE);
	}
	if (game->map_info.map[i][j] == EXIT)
		mlx_put_image_to_window(game->mlx, game->win,
			game->tile_info.tile_exit.ptr, j * TILE, i * TILE);
	else if (game->map_info.map[i][j] == COLLECTIBLE)
		mlx_put_image_to_window(game->mlx, game->win,
			game->tile_info.tile_collectible.ptr, j * TILE, i * TILE);
}

void	draw_player(t_game *game)
{
	int	x_add;
	int	y_add;
	int	i;
	int	j;

	if (game->fin == TRUE)
		return ;
	if (game->map_info.player.x != game->map_info.player.x_b
		|| game->map_info.player.y != game->map_info.player.y_b)
		game->frame++;
	i = game->map_info.player.y_b;
	j = game->map_info.player.x_b;
	x_add = (game->map_info.player.x - j) * game->frame * 4;
	y_add = (game->map_info.player.y - i) * game->frame * 4;
	mlx_put_image_to_window(game->mlx, game->win,
		game->tile_info.tile_player.ptr, j * TILE + x_add, i * TILE + y_add);
	if (game->frame == 12)
	{
		game->frame = 0;
		game->map_info.player.x_b = game->map_info.player.x;
		game->map_info.player.y_b = game->map_info.player.y;
	}
}

void	draw_attack(t_game *game)
{
	int	x;
	int	y;

	x = game->map_info.player.x;
	y = game->map_info.player.y;
	mlx_put_image_to_window(game->mlx, game->win,
		game->tile_info.tile_attack[game->frame / 2].ptr, x * TILE, y * TILE);
	game->frame++;
	if (game->frame == 20)
	{
		game->frame = 0;
		game->map_info.map[y][x] = EMPTY;
	}
}

void	draw_enemy(t_game *game, int i, int j)
{
	static int	f = 0;

	mlx_put_image_to_window(game->mlx, game->win,
		game->tile_info.tile_enemy[f / 4].ptr, j * TILE - 8, i * TILE - 16);
	f++;
	if (f == 32)
		f = 0;
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_info.row)
	{
		j = 0;
		while (j < game->map_info.col)
		{
			mlx_put_image_to_window(game->mlx, game->win,
				game->tile_info.tile_empty.ptr, j * TILE, i * TILE);
			draw_component(game, i, j);
			if (game->map_info.map[i][j] == ENEMY)
				draw_enemy(game, i, j);
			j++;
		}
		i++;
	}
	draw_step(game);
	if (game->map_info.map[game->map_info.player.y_b][game->map_info.player.x_b] != COLLECTIBLE)
		draw_player(game);
	else
		draw_attack(game);
}
