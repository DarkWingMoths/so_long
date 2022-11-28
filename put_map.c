/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:52:50 by mgagnon           #+#    #+#             */
/*   Updated: 2022/11/27 04:33:06 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*put_img(char img, int x, int y, t_mlx *mlx)
{
	if (img == '1')
		return (mlx->ass->wall[4]);
	else if (img == 'P')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->window, \
				mlx->ass->empty, x * 64, y *64);
		mlx->map->map[y][x] = '0';
		return (mlx->ass->play[3]);
	}
	else if (img == 'C')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->window, \
				mlx->ass->empty, x * 64, y * 64);
		return (mlx->ass->coll);
	}
	else if (img == 'E')
		return (mlx->ass->exit[0]);
	else if (img == '0')
		return (mlx->ass->empty);
	else
		return (NULL);
}

void	put_map(t_mlx *mlx)
{
	int	x;
	int	y;
	void	*img;

	y = 1;
	set_assets(mlx);
	mlx->window = mlx_new_window(mlx->mlx, ((mlx->map->x_max + 1) * 64), \
			((mlx->map->y_max + 1) * 64), "so_long mgagnon");
	put_outer_wall(mlx);
	while (y < mlx->map->y_max)
	{
		x = 1;
		while (x < mlx->map->x_max)
		{
			img = put_img(mlx->map->map[y][x], x, y, mlx);
			mlx_put_image_to_window(mlx->mlx, mlx->window, \
					img, x * 64, y * 64);
			x++;
		}
		y++;
	}
}
