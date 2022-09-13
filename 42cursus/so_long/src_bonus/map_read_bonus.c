/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:17:37 by balee             #+#    #+#             */
/*   Updated: 2022/09/13 05:06:45 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	file_open(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_err("Notice: File open fail\n");
	return (fd);
}

void	map_malloc(t_game *game)
{
	int	i;

	i = 0;
	game->map_info.map = (char **)malloc(sizeof(char *)
			* (game->map_info.row + 1));
	if (game->map_info.map == NULL)
		exit_err("Notice: Memory allocation fail\n");
	while (i < game->map_info.row)
	{
		game->map_info.map[i] = (char *)malloc(sizeof(char)
				* (game->map_info.col + 1));
		if (game->map_info.map[i] == NULL)
			exit_err("Notice: Memory allocation fail\n");
		i++;
	}
}

void	map_load(t_game *game, int fd)
{
	int	i;

	i = 0;
	map_malloc(game);
	while (i < game->map_info.row)
	{
		read(fd, game->map_info.map[i], game->map_info.col + 1);
		game->map_info.map[i][game->map_info.col] = '\0';
		i++;
	}
	game->map_info.map[i] = NULL;
	close(fd);
}

void	map_read(t_game *game, char *file)
{
	check_extention(file, ".ber");
	check_row_col(game, file_open(file));
	map_load(game, file_open(file));
	check_map(&game->map_info);
}
