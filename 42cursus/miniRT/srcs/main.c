/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:36:08 by balee             #+#    #+#             */
/*   Updated: 2023/02/12 13:53:06 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	init_miniRT(t_miniRT *miniRT)
{
	miniRT->mlx = mlx_init();
	miniRT->win = mlx_new_window(miniRT->mlx, WIDTH, HEIGHT, "miniRT");
}

int	main()
{
	t_miniRT	miniRT;

	init_miniRT(&miniRT);
	mlx_hook(miniRT.win, KEY_PRESS, 0, &key_press, &miniRT);
	mlx_hook(miniRT.win, DESTROY_NOTIFY, 0, &destroy_notify, &miniRT);
	mlx_loop(miniRT.mlx);
	return (0);
}
