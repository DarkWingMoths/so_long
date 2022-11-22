/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:26:45 by mgagnon           #+#    #+#             */
/*   Updated: 2022/11/22 10:55:29 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_outer_wall(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y <= mlx->map->y_max)
	{
		x = 0;
		while (x <= mlx->map->x_max)
		{
			mlx_put_image_to_window(mlx->mlx, mlx->window, \
					mlx->wall, (x * 64), (y * 64));
			x++;
		}
		y = mlx->map->y_max;
	}
	y = 1;
	while (y < mlx->map->y_max)
	{
		x = 0;
		while (x <= mlx->map->x_max)
		{
			mlx_put_image_to_window(mlx->mlx, mlx->window, \
					mlx->wall, (x * 64), (y * 64));
			x = mlx->map->x_max;
		}
		y++;
	}
}
