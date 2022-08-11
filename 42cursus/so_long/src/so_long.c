/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:17:18 by balee             #+#    #+#             */
/*   Updated: 2022/08/12 03:54:52 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	exit_err(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	exit(1);
}

int	main_loop(t_game *game)
{
	draw_map(game);
	return (0);
}

int	destroy_notify(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit_err("Notice: Undefined execution\n");
	map_read(&game, argv[1]);
	init_game(&game);
	mlx_hook(game.win, KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.win, DESTROY_NOTIFY, 0, &destroy_notify, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	exit(0);
}
