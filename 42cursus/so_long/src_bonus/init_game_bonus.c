/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 03:27:41 by balee             #+#    #+#             */
/*   Updated: 2022/09/13 13:32:50 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	init_window(t_game *game)
{
	int	width;
	int	height;

	game->mlx = mlx_init();
	if (game->mlx == NULL)
		exit_err("Notice: MiniLibX unavailable\n");
	width = game->map_info.col * TILE;
	height = game->map_info.row * TILE;
	game->win = mlx_new_window(game->mlx, width, height, "so_long");
	if (game->win == NULL)
		exit_err("Notice: Create new window fail\n");
}

void	xpm_load(t_game *game, t_img *img, char *path)
{
	img->ptr = mlx_xpm_file_to_image(game->mlx, path,
			&img->width, &img->height);
	if (img->ptr == NULL)
		exit_err("Notice: Texture load fail\n");
}

void	init_texture(t_game *game)
{
	xpm_load(game, &game->tile_info.tile_empty, "./tile/empty.xpm");
	xpm_load(game, &game->tile_info.tile_wall_1, "./tile/wall1.xpm");
	xpm_load(game, &game->tile_info.tile_wall_2, "./tile/wall2.xpm");
	xpm_load(game, &game->tile_info.tile_exit, "./tile/exit.xpm");
	xpm_load(game, &game->tile_info.tile_player, "./tile/player.xpm");
	xpm_load(game, &game->tile_info.tile_collectible, "./tile/collectible.xpm");
	xpm_load(game, &game->tile_info.tile_grass_1, "./tile/grass1.xpm");
	xpm_load(game, &game->tile_info.tile_grass_2, "./tile/grass2.xpm");
	xpm_load(game, &game->tile_info.tile_lake, "./tile/lake.xpm");
	xpm_load(game, &game->tile_info.tile_attack[0], "./tile/Attack0.xpm");
	xpm_load(game, &game->tile_info.tile_attack[1], "./tile/Attack1.xpm");
	xpm_load(game, &game->tile_info.tile_attack[2], "./tile/Attack2.xpm");
	xpm_load(game, &game->tile_info.tile_attack[3], "./tile/Attack3.xpm");
	xpm_load(game, &game->tile_info.tile_attack[4], "./tile/Attack4.xpm");
	xpm_load(game, &game->tile_info.tile_attack[5], "./tile/Attack5.xpm");
	xpm_load(game, &game->tile_info.tile_attack[6], "./tile/Attack6.xpm");
	xpm_load(game, &game->tile_info.tile_attack[7], "./tile/Attack7.xpm");
	xpm_load(game, &game->tile_info.tile_attack[8], "./tile/Attack8.xpm");
	xpm_load(game, &game->tile_info.tile_attack[9], "./tile/Attack9.xpm");
}

void	init_enemy(t_game *game)
{
	xpm_load(game, &game->tile_info.tile_enemy[0], "./tile/enemy0.xpm");
	xpm_load(game, &game->tile_info.tile_enemy[1], "./tile/enemy1.xpm");
	xpm_load(game, &game->tile_info.tile_enemy[2], "./tile/enemy2.xpm");
	xpm_load(game, &game->tile_info.tile_enemy[3], "./tile/enemy3.xpm");
	xpm_load(game, &game->tile_info.tile_enemy[4], "./tile/enemy4.xpm");
	xpm_load(game, &game->tile_info.tile_enemy[5], "./tile/enemy5.xpm");
	xpm_load(game, &game->tile_info.tile_enemy[6], "./tile/enemy6.xpm");
	xpm_load(game, &game->tile_info.tile_enemy[7], "./tile/enemy7.xpm");
}

void	init_game(t_game *game)
{
	init_window(game);
	init_texture(game);
	init_enemy(game);
	game->step = 0;
	game->frame = 0;
	game->enemy_frame = 0;
	game->fin = FALSE;
}
