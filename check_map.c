/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:03:27 by mgagnon           #+#    #+#             */
/*   Updated: 2022/11/21 00:28:09 by mgagnon          ###   ########.fr       */
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
	}
	return (1);
}

int	check_row(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i])
	{
		printf("row to check map[%i] = %s\n", i, map->map[i]);
		while (map->map[i][j])
		{
			if (!strrchr("10CEP", map->map[i][j]))
			{
				error_log("invalid character inside map!");
				return (0);
			}
			printf("valid character\n");
			printf("check for wall\n");
			if (is_wall(map, i, j) == 0)
				return (0);
			j++;
		}
		i++;
	}
	set_origin();
	return (1);
}

void	get_size(t_map *map, char *map_dir)
{
	int		map_fd;
	char	*tmp;

	printf("opening file %s\n", map_dir);
	map_fd = open(map_dir, O_RDONLY);
	if (map_fd == -1)
	{
		error_log("loading map!");
		close(map_fd);
		exit(0);
	}
	printf("file opened\n");
	printf("check first line of %s\n", map_dir);
	tmp = get_next_line(map_fd);
	printf("first line checked\ntmp = %s\n", tmp);
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
			exit(0);
		}
		printf("check next line...\n");
		free(tmp);
		tmp = get_next_line(map_fd);
		printf("line checked\ntmp = %s\n", tmp);
		map->y_max += 1;
	}
	close(map_fd);
	free(tmp);
	printf("x_max = %i\ny_max = %i\n", map->x_max, map->y_max);
}

void	store_map(t_mlx *mlx, char *map)
{
	int	i;
	int	map_fd;

	i = 0;
	printf("opening file ...\n");
	map_fd = open(map, O_RDONLY);
	if (map_fd == -1)
	{
		error_log("loading map!");
		close(map_fd);
		exit(0);
	}
	printf("file opened\n");
	mlx->map->map = ft_calloc((mlx->map->y_max + 1), sizeof(char));
	if (!mlx->map->map)
		clean_exit(mlx, 0);
	while (i <= mlx->map->y_max)
	{
		mlx->map->map[i] = ft_calloc((mlx->map->x_max + 1), sizeof(char));
		if (!mlx->map->map[i])
			exit (0);
			/* clean_exit(mlx, 0); */
		mlx->map->map[i] = get_next_line(map_fd);
		printf("map[%i] = %s\n", i, mlx->map->map[i]);
		i++;
	}
	close(map_fd);
}

void	check_map(t_mlx *mlx, char *map_dir)
{
	int	i;

	i = 0;
	printf("getting size\n{\n");
	get_size(mlx->map, map_dir);
	printf("}	get size done\n");
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
	printf("size valide\n");
	printf("Storing map\n{\n");
	store_map(mlx, map_dir);
	printf("}	map stored\n");
	while (mlx->map->map[i])
	{
		printf("%s\n", mlx->map->map[i]);
		i++;
	}
	printf("\nchecking row\n{\n");
	/* if (!check_row(mlx->map)) */
	/* 	clean_exit(mlx, 0); */
	/* if (!valid_map()) */
	/* 	clean_exit(mlx, 0); */
}
