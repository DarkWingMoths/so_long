/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:03:27 by mgagnon           #+#    #+#             */
/*   Updated: 2022/11/18 12:11:24 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_wall(t_map *map, int y, int x)
{
	if (x == 0 || x == map->x_max || y == 0 || y == map->y_max)
	{
		if (map->map[y][x] != 1)
		{
			error_log("map needs rectangular outer wall!");
			return (0);
		}
		else
			return (1);
	}
}

int	check_row(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		while (map->map[i][j])
		{
			if (!strrchr("10CEP", map->map[i][j]))
			{
				error_log("invalid character inside map!");
				return (0);
			}
			if (!is_wall(map, i, j))
			{
				return (0);
			}
			set_origin();
			j++;
		}
		i++;
	}
	return (1);
}

void	get_size(t_map *map, char *map_dir)
{
	int		map_fd;
	char	*tmp;

	map_fd = open(map_dir, O_RDONLY);
	if (map_fd == -1)
	{
		error_log("loading map!");
		close(map_fd);
		exit(0);
	}
	tmp = get_next_line(map_fd);
	map->x_max = ft_strlen(tmp);
	map->y_max = 0;
	while (tmp)
	{
		if (ft_strlen(tmp) != map->x_max)
		{
			error_log("bad map!");
			close(map_fd);
			exit(0);
		}
		tmp = get_next_line(map_fd);
		map->y_max += 1;
	}
	close(map_fd);
}

void	store_map(t_mlx *mlx, char *map)
{
	int	i;
	int	map_fd;

	i = 0;
	map_fd = open(map, O_RDONLY);
	if (map_fd == -1)
	{
		error_log("loading map!");
		close(map_fd);
		exit(0);
	}
	mlx->map->map = ft_calloc(mlx->map->y_max, sizeof(char));
	if (!mlx->map)
		clean_exit(mlx, 0);
	while (i <= mlx->map->y_max)
	{
		mlx->map->map[i] = ft_calloc(mlx->map->x_max, sizeof(char));
		if (!mlx->map->map[i])
			clean_exit(mlx, 0);
		mlx->map->map[i] = get_next_line(map_fd);
		i++;
	}
	close(map_fd);
}

void	check_map(t_mlx *mlx, char *map_dir)
{
	get_size(mlx->map, map_dir);
	if ((mlx->map->x_max == 3 && mlx->map->y_max < 5)
		|| (mlx->map->y_max == 3 && mlx->map->x_max < 5))
	{
		error_log("map too small!");
		exit(0);
	}
	if (mlx->map->x_max < 4 && mlx->map->y_max < 4)
	{
		error_log("map too small!");
		exit(0);
	}
	if (mlx->map->x_max > 30 || mlx->map->y_max > 16)
	{
		error_log("map too big for screen!");
		exit(0);
	}
	store_map(mlx, map_dir);
	if (!check_row(mlx->map))
		clean_exit(mlx, 0);
	if (!valid_map())
		clean_exit(mlx, 0);
}
