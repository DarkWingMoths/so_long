/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:03:03 by mgagnon           #+#    #+#             */
/*   Updated: 2022/11/26 17:09:07 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood(t_map *map, int x, int y)
{
	static int	coll_nb;

	if (!coll_nb)
		coll_nb = map->coll_nb;
	if ((x >= 0 || x <= map->x_max) && (y >= 0 || y <= map->y_max))
	{
		if (map->map[y][x] != 'D')
		{
			if (map->map[y][x] == 'C')
				coll_nb--;
			else if (map->map[y][x] == '1')
				return (coll_nb);
			else if (map->map[y][x] == 'E' && map->coll_nb == 0)
				return (coll_nb);
			if (map->map[y][x] != 'E' || map->map[y][x] != '1')
				map->map[y][x] = 'D';
		}
		flood(map, (x + 1), y);
		flood(map, x, (y + 1));
		flood(map, (x - 1), y);
		flood(map, x, (y - 1));
	}
	return (coll_nb);
}
int	valid_map(void)
{
	t_mlx	*mlx;

	mlx = get_data();
	if (mlx->map->exit_nb != 1 || mlx->map->start_nb != 1 || \
			mlx->map->coll_nb == 0)
	{
		error_log("invalid map!");
		return (0);
	}
	if (flood(mlx->map, mlx->pos_x, mlx->pos_y) != 0)
	{
		error_log("no valid path!");
		return (0);
	}
	return (1);
}
