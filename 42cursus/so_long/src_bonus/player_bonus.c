/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 03:52:09 by balee             #+#    #+#             */
/*   Updated: 2022/09/13 13:05:27 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	print_step(int step)
{
	ft_putstr_fd("Step: ", 1);
	ft_putnbr_fd(step, 1);
	ft_putstr_fd("\n", 1);
}

void	move_player(t_game *game, int add_x, int add_y)
{
	int	i;
	int	j;

	i = game->map_info.player.y + add_y;
	j = game->map_info.player.x + add_x;
	if (game->map_info.map[i][j] == WALL)
		return ;
	print_step(++game->step);
	game->map_info.player.y = i;
	game->map_info.player.x = j;
	if (game->map_info.map[i][j] == COLLECTIBLE)
		game->map_info.colletion--;
}

int	key_press(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit(0);
	else if (game->fin == TRUE)
		return (0);
	else if (game->frame != 0)
		return (0);
	else if (key_code == KEY_W)
		move_player(game, 0, -1);
	else if (key_code == KEY_A)
		move_player(game, -1, 0);
	else if (key_code == KEY_S)
		move_player(game, 0, +1);
	else if (key_code == KEY_D)
		move_player(game, +1, 0);
	return (0);
}
