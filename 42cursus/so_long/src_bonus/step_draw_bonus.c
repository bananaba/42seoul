/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_draw_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:06:06 by balee             #+#    #+#             */
/*   Updated: 2022/09/13 13:06:07 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	find_figures(int n)
{
	int				figures;
	unsigned int	temp;

	figures = 0;
	temp = n;
	if (n <= 0)
	{
		figures++;
		temp = -n;
	}
	while (temp)
	{
		figures++;
		temp /= 10;
	}
	return (figures);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				figures;
	unsigned int	temp;

	figures = find_figures(n);
	str = (char *)malloc(sizeof(char) * (figures + 1));
	if (!str)
		return (0);
	str[figures--] = 0;
	temp = n;
	if (n < 0)
	{
		str[0] = '-';
		temp = -n;
	}
	while (figures >= 0)
	{
		str[figures--] = temp % 10 + '0';
		temp /= 10;
		if (!temp)
			figures--;
	}
	return (str);
}

void	draw_step(t_game *game)
{
	char	*str;

	str = ft_itoa(game->step);
	mlx_put_image_to_window(game->mlx, game->win,
		game->tile_info.tile_lake.ptr, 0, 0);
	mlx_string_put(game->mlx, game->win, 16, 32, 0xffff00, str);
}
