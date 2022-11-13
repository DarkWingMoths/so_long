/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:03:27 by mgagnon           #+#    #+#             */
/*   Updated: 2022/11/13 16:33:25 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_column(t_mlx *mlx, char *map)
{
}

int	check_row(t_mlx *mlx)
{
	char	*tmp;

	while (tmp != '\0')
	{
		tmp = get_next_line(fd);
	}
}

void	get_size(t_mlx *mlx, char *map)
{
	int	map_fd;
	char	*tmp;

	map_fd = open(map, O_RDONLY);
	if (map_fd == -1)
	{
		error_log("loading map!");
		close(map_fd);
		exit(0);
	}
	tmp = get_next_line(map_fd);
	mlx->x_max = ft_strlen(tmp);
	mlx->y_max = 1;
	while (tmp)
	{
		mlx->y_max += 1;
		if (ft_strlen(tmp) != mlx->x_max)
		{
			error_log("bad map!");
			close(map_fd);
			exit(0);
		}
		tmp = get_next_line(map_fd);
	}
	close(map_fd);
}

void	store_map(t_mlx *mlx, char *map)
{
	int	i;
	int	map_fd;

	i = 0;
	mlx->map = ft_calloc(mlx->y_max, sizeof(char));
	if (!mlx->map)
	{
		free(mlx->map);
		exit(0);
	}
	while (i <= mlx->y_max)
	{
		mlx->map[i] = ft_calloc(mlx->x_max, sizeof(char));
		if (!mlx->map[i])

	}
}
void	check_map(t_mlx *mlx, char *map)
{
	get_size(mlx, map);
	store_map(mlx, map);
	check_row(mlx);
}
