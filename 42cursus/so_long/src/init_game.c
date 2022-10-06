/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 03:27:41 by balee             #+#    #+#             */
/*   Updated: 2022/09/13 09:15:55 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
}

void	init_game(t_game *game)
{
	init_window(game);
	init_texture(game);
	game->step = 0;
	game->frame = 0;
	game->fin = FALSE;
}
