/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:36:08 by balee             #+#    #+#             */
/*   Updated: 2023/02/17 17:14:03 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	key_hook(int keycode, void *param)
{
	if (keycode == 53)
		destroy_notify(param);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_miniRT	minirt;

	if (argc != 2)
		exit_err(NULL);
	init_minirt(&minirt, argv[1]);
	draw(minirt);
	mlx_put_image_to_window(minirt.mlx, minirt.win, minirt.img.img, 0, 0);
	mlx_hook(minirt.win, DESTROY_NOTIFY, 0, &destroy_notify, &minirt);
	mlx_key_hook (minirt.win, key_hook, &minirt);
	mlx_loop(minirt.mlx);
	free_all(&minirt);
	return (0);
}
