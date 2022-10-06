/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:17:41 by balee             #+#    #+#             */
/*   Updated: 2022/09/13 13:13:28 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	check_extention(char *file, char *ext)
{
	while (*file != '\0')
	{
		if (*file == '.' && !(*(file + 1) == '/'
				|| (*(file + 1) == '.' && *(file + 2) == '/')))
			break ;
		file++;
	}
	if (*file == '\0')
		exit_err("Notice: Undefined extention or file path\n");
	while (*file != '\0' && *ext != '\0')
	{
		file++;
		ext++;
		if (*file != *ext)
			exit_err("Notice: Undefined extention or file path\n");
	}
}

void	check_row_col(t_game *game, int fd)
{
	char	buf;
	int		col;

	game->map_info.row = 0;
	game->map_info.col = 0;
	col = 0;
	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
		{
			if (game->map_info.col == 0 && col != 0)
				game->map_info.col = col;
			else if (game->map_info.col == 0 && col == 0)
				exit_err("Notice: Invalid map format\n");
			else if (game->map_info.col != col && col != 0)
				exit_err("Notice: Invalid map format\n");
			game->map_info.row++;
			col = 0;
		}
		else
			col++;
	}
	close(fd);
}

void	check_number_of_component(t_map *map_info, int cnt_exit, int cnt_player)
{
	if (cnt_exit != 1 || cnt_player != 1 || map_info->colletion < 1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Notice: Invalid number of map component", 2);
		ft_putstr_fd("\nEXIT:        ", 2);
		ft_putnbr_fd(cnt_exit, 2);
		ft_putstr_fd("\nCOLLECTIBLE: ", 2);
		ft_putnbr_fd(map_info->colletion, 2);
		ft_putstr_fd("\nPLAYER:      ", 2);
		ft_putnbr_fd(cnt_player, 2);
		ft_putstr_fd("\n", 2);
		exit(1);
	}
	map_info->map[0][0] = EMPTY;
}

void	check_component(t_map *map_info, int i, int j)
{
	static int	cnt_exit = 0;
	static int	cnt_player = 0;

	if (i == map_info->row - 1 && j == map_info->col - 1)
		check_number_of_component(map_info, cnt_exit, cnt_player);
	else if (map_info->map[i][j] == EXIT)
		cnt_exit++;
	else if (map_info->map[i][j] == PLAYER)
	{
		cnt_player++;
		map_info->map[i][j] = EMPTY;
		map_info->player.y = i;
		map_info->player.x = j;
		map_info->player.y_b = i;
		map_info->player.x_b = j;
	}
	else if (map_info->map[i][j] == COLLECTIBLE)
		map_info->colletion++;
	else
		exit_err("Notice: Undefined map component\n");
}

void	check_map(t_map *map_info)
{
	int	i;
	int	j;

	i = 0;
	map_info->colletion = 0;
	while (i < map_info->row)
	{
		j = 0;
		while (j < map_info->col)
		{
			if ((i == 0 || i == map_info->row - 1)
				&& map_info->map[i][j] != WALL)
				exit_err("Notice: Invalid map format\n");
			else if ((j == 0 || j == map_info->col - 1)
				&& map_info->map[i][j] != WALL)
				exit_err("Notice: Invalid map format\n");
			else if (map_info->map[i][j] != WALL
				&& map_info->map[i][j] != EMPTY)
				check_component(map_info, i, j);
			else if (i == map_info->row - 1 && j == map_info->col - 1)
				check_component(map_info, i, j);
			j++;
		}
		i++;
	}
}
