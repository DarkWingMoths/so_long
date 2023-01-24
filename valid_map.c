/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:03:03 by mgagnon           #+#    #+#             */
/*   Updated: 2023/01/23 14:19:45 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_cpy(t_map *map)
{
	char	**dup;
	int	i;

	i = 0;
	dup = ft_calloc(map->y_max + 1, sizeof(char *));
	while (i <= map->y_max && map->map[i])
	{
		dup[i] = ft_strdup(map->map[i]);
		i++;
	}
	return (dup);
}

int	flood(t_map *map, int x, int y)
{
	static int	coll_nb = -1;

	if (coll_nb == -1)
		coll_nb = map->coll_nb;
	if (x >= 0 && x <= map->x_max && y >= 0 && y <= map->y_max)
	{
		if (map->map_dup[y][x] == 'D')
			return (coll_nb);
		else
		{
			if (map->map_dup[y][x] == 'C')
				coll_nb--;
			else if (map->map_dup[y][x] == '1')
				return (coll_nb);
			else if (map->map_dup[y][x] == 'E')
				map->exit_check++;
			map->map_dup[y][x] = 'D';
		}
		flood(map, (x + 1), y);
		flood(map, x, (y + 1));
		flood(map, (x - 1), y);
		flood(map, x, (y - 1));
	}
	return (coll_nb);
}
int	valid_map(t_mlx *mlx)
{
	if (!mlx->map->map_dup)
		mlx->map->map_dup = map_cpy(mlx->map);
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
	else if (mlx->map->exit_check != 1)
	{
		error_log("no valid path!");
		return (0);
	}
	free_map(mlx->map->map_dup, mlx->map->y_max);
	return (1);
}
