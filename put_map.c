/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:52:50 by mgagnon           #+#    #+#             */
/*   Updated: 2022/11/21 00:38:48 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*put_img(char img, int x, int y, t_mlx *mlx)
{
	if (img == '1')
		return (put_wall(x, y, mlx));
	else if (img == 'P')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->window, \
				mlx->ass->empty, x, y);
		return (mlx->ass->play[3]);
	}
	else if (img == 'C')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->window, \
				mlx->ass->empty, x, y);
		return (mlx->ass->coll);
	}
	else if (img == 'E')
		return (mlx->ass->exit);
	else
		return (mlx->ass->empty);
}

void	put_map(t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	set_assets(mlx);
	mlx->window = mlx_new_window(mlx->mlx, ((mlx->map->x_max + 1) * 64), \
			((mlx->map->y_max + 1) * 64), "so_long mgagnon");
	while (y <= mlx->map->y_max)
	{
		while (x <= mlx->map->x_max)
		{
			mlx_put_image_to_window(mlx->mlx, mlx->window, \
					put_img(mlx->map->map[y][x], x, y, \
						mlx), x * 64, y * 64);
			x++;
			printf("img %i of row %i is put\n", x, y);
		}
		printf("first row put\n");
		x = 0;
		y++;
	}
}
