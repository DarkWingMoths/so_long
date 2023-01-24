/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:03:27 by mgagnon           #+#    #+#             */
/*   Updated: 2023/01/23 16:58:01 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y <= map->y_max)
	{
		x = 0;
		while (x <= map->x_max)
		{
			if (map->map[y][x] != '1')
			{
				error_log("map needs rectangular outer wall!");
				return (0);
			}
			if (y != 0 && y != map->y_max)
			{
				if (x != map->x_max)
					x = map->x_max;
				else
					x++;
			}
			else
				x++;
		}
		y++;
	}
	return (1);
}

int	check_row(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y <= map->y_max)
	{
		x = 0;
		while (map->map[y][x] || x <= map->x_max)
		{
			if (!strrchr("10CEP\n", map->map[y][x]))
			{
				error_log("invalid character inside map!");
				return (0);
			}
			if (map->map[y][x] == '\n')
				map->map[y][x] = '\0';
			x++;
		}
		y++;
	}
	return (1);
}

int	get_size(t_map *map, char *map_dir)
{
	int		map_fd;
	char	*tmp;

	map_fd = open(map_dir, O_RDONLY);
	if (map_fd == -1)
	{
		error_log("loading map!");
		close(map_fd);
		return(0);
	}
	tmp = get_next_line(map_fd);
	if(!tmp[0])
	{
		error_log("empty map!");
		free (tmp);
		return (0);
	}
	map->x_max = ft_strlen(tmp) - 2;
	map->y_max = -1;
	while (tmp)
	{
		if ((ft_strlen(tmp) - 2) != map->x_max)
		{
			error_log("bad map!");
			free(tmp);
			close(map_fd);
			return (0);;
		}
		ft_bzero(tmp, ft_strlen(tmp));
		free(tmp);
		tmp = get_next_line(map_fd);
		map->y_max += 1;
	}
	close(map_fd);
	ft_bzero(tmp, ft_strlen(tmp));
	free(tmp);
	return (1);
}

void	check_map(t_mlx *mlx, char *map_dir)
{
	static	t_map	map;

	mlx->map = &map;
	if (!get_size(&map, map_dir))
		clean_exit(mlx, 1);
	if ((map.x_max == 3 && map.y_max < 5)
		|| (mlx->map->y_max == 3 && mlx->map->x_max < 5))
	{
		error_log("map too small!");
		exit(1);
	}
	if (map.x_max < 4 && map.y_max < 4)
	{
		error_log("map too small!");
		exit(1);
	}
	if (map.x_max > 39 || map.y_max > 19)
	{
		error_log("map too big for screen!");
		exit(1);
	}
}
