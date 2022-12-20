/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:03:27 by mgagnon           #+#    #+#             */
/*   Updated: 2022/12/20 16:03:29 by mgagnon          ###   ########.fr       */
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
			if (!strrchr("10CEP", map->map[y][x]))
			{
				error_log("invalid character inside map!");
				return (0);
			}
			x++;
		}
		y++;
	}
	set_origin();
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
	map->x_max = ft_strlen(tmp) - 1;
	map->y_max = -1;
	while (tmp)
	{
		if (tmp[ft_strlen(tmp)] == '\n')
			tmp[ft_strlen(tmp)] = '\0';
		if ((ft_strlen(tmp) - 1) != map->x_max)
		{
			error_log("bad map!");
			close(map_fd);
			break;
		}
		ft_bzero(tmp, ft_strlen(tmp));
		free(tmp);
		tmp = get_next_line(map_fd);
		map->y_max += 1;
	}
	close(map_fd);
	ft_bzero(tmp, ft_strlen(tmp));
	free(tmp);
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
		exit(1);
	}
	mlx->map->map = ft_calloc((mlx->map->y_max + 1), sizeof(char *));
	if (!mlx->map->map)
		clean_exit(mlx, 1);
	while (i <= mlx->map->y_max)
	{
		mlx->map->map[i] = ft_calloc((mlx->map->x_max + 1), sizeof(char *));
		if (!mlx->map->map[i])
			exit(1);
		mlx->map->map[i] = get_next_line(map_fd);
		i++;
	}
	close(map_fd);
}

void	check_map(t_mlx *mlx, char *map_dir)
{
	if (!get_size(mlx->map, map_dir))
		clean_exit(mlx, 1);
	printf("size = %iX%i\n", mlx->map->x_max + 1, mlx->map->y_max + 1);
	if ((mlx->map->x_max == 3 && mlx->map->y_max < 5)
		|| (mlx->map->y_max == 3 && mlx->map->x_max < 5))
	{
		error_log("map too small!");
		exit(1);
	}
	if (mlx->map->x_max < 4 && mlx->map->y_max < 4)
	{
		error_log("map too small!");
		exit(1);
	}
	if (mlx->map->x_max > 39 || mlx->map->y_max > 19)
	{
		error_log("map too big for screen!");
		exit(1);
	}
	store_map(mlx, map_dir);
	if (!check_wall(mlx->map))
		clean_exit(mlx, 1);
	if (!check_row(mlx->map))
		clean_exit(mlx, 1);
	if (!valid_map())
		clean_exit(mlx, 1);
}
