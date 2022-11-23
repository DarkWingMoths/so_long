/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:26:45 by mgagnon           #+#    #+#             */
/*   Updated: 2022/11/23 14:46:44 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_corner(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->ass->corn[0], 0, 0);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->ass->corn[1], mlx->map->x_max * 64, 0);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->ass->corn[2], 0, mlx->map->y_max * 64);
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->ass->corn[3], mlx->map->x_max * 64, mlx->map->y_max * 64);
}

void	put_outer_wall(t_mlx *mlx)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	x = 1;
	put_corner(mlx);
	while (x < mlx->map->x_max)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->window, \
				mlx->ass->wall[0], (x * 64), (y * 64));
		x++;
	}
	x = 0;
	y = 1;
	while (y < mlx->map->y_max)
	{
		i = 2;
		x = 0;
		while (x <= mlx->map->x_max && i < 4)
		{
			mlx_put_image_to_window(mlx->mlx, mlx->window, \
					mlx->ass->wall[i], (x * 64), (y * 64));
			x = mlx->map->x_max;
			i++;
		}
		y++;
	}
	x = 1;
	y = mlx->map->y_max;
	while (x < mlx->map->x_max)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->window, \
				mlx->ass->wall[1], (x * 64), (y * 64));
		x++;
	}
}
