/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:01:23 by mgagnon           #+#    #+#             */
/*   Updated: 2023/01/25 22:13:04 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	anim_coll(t_mlx *mlx)
{
	while (mlx->map->map[y][x] == 'C')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->ass->coll, (x + 2) * 64, y * 64);
		usleep(800);
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->ass->coll, (x + 5) * 64, y * 64);
		usleep(800);
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->ass->coll, (x + 2) * 64, y * 64);
		usleep(800);
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->ass->coll, x * 64, y * 64);
		usleep(800);
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->ass->coll, (x - 2) * 64, y * 64);
		usleep(800);
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->ass->coll, (x - 5) * 64, y * 64);
		usleep(800);
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->ass->coll, (x - 2) * 64, y * 64);
		usleep(800);
	}
}

