/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:52:50 by mgagnon           #+#    #+#             */
/*   Updated: 2022/11/22 12:09:20 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*put_img(char img, int x, int y, t_mlx *mlx)
{
	if (img == '1')
		return (mlx->wall);
	else if (img == 'P')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->window, \
				mlx->empty, x * 64, y *64);
		return (mlx->play);
	}
	else if (img == 'C')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->window, \
				mlx->empty, x * 64, y * 64);
		return (mlx->coll);
	}
	else if (img == 'E')
		return (mlx->exit);
	else if (img == '0')
		return (mlx->empty);
	else
		return (NULL);
}

void	put_map(t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	printf("setting assets\n");
	set_assets(mlx);
	printf("assets set\n");
	printf("setting window\n");
	mlx->window = mlx_new_window(mlx->mlx, ((mlx->map->x_max + 1) * 64), \
			((mlx->map->y_max + 1) * 64), "so_long mgagnon");
	printf("window set\n");
	/* printf("putting outer wall\n"); */
	/* put_outer_wall(mlx); */
	/* printf("wall put\n"); */
	while (y <= mlx->map->y_max)
	{
		while (x <= mlx->map->x_max)
		{
			mlx_put_image_to_window(mlx->mlx, mlx->window, \
					put_img(mlx->map->map[y][x], x, y, \
						mlx), x * 64, y * 64);
			x++;
		}
		x = 0;
		y++;
	}
}
