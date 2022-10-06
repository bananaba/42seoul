/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:17:11 by balee             #+#    #+#             */
/*   Updated: 2022/09/13 05:02:56 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../mlx/mlx.h"
# include "key.h"

# define TRUE			1
# define FALSE			0
# define TILE			48
# define WALL			'1'
# define COLLECTIBLE	'C'
# define EXIT			'E'
# define PLAYER			'P'
# define EMPTY			'0'

typedef struct s_player
{
	int	x;
	int	y;
	int	x_b;
	int	y_b;
}	t_player;

typedef struct s_map
{
	int			row;
	int			col;
	int			colletion;
	char		**map;
	t_player	player;
}	t_map;

typedef struct s_img
{
	void	*ptr;
	int		*data;
	int		height;
	int		width;
}	t_img;

typedef struct s_tile
{
	t_img	tile_empty;
	t_img	tile_wall_1;
	t_img	tile_wall_2;
	t_img	tile_exit;
	t_img	tile_player;
	t_img	tile_collectible;
	t_img	tile_grass_1;
	t_img	tile_grass_2;
}	t_tile;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		frame;
	int		step;
	int		fin;
	t_map	map_info;
	t_tile	tile_info;
}	t_game;

size_t	ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_bzero(void *s, size_t n);

void	map_read(t_game *game, char *file);
void	map_load(t_game *game, int fd);
void	map_malloc(t_game *game);
void	check_map(t_map *map_info);
void	check_component(t_map *map_info, int i, int j);
void	check_number_of_component(t_map *map_info, int exit, int player);
void	check_row_col(t_game *game, int fd);
void	check_extention(char *file, char *ext);
int		file_open(char *file);

void	init_game(t_game *game);
void	init_window(t_game *game);
void	init_texture(t_game *game);
void	xpm_load(t_game *game, t_img *img, char *path);

void	draw_map(t_game *game);
void	draw_component(t_game *game, int i, int j);

int		key_press(int key_code, t_game *game);

void	exit_err(char *str);

#endif
