/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:03:27 by mgagnon           #+#    #+#             */
/*   Updated: 2022/11/10 14:28:55 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_column(t_mlx *mlx, char *map)
{
}

int	check_row(char *map)
{
}

void	check_map(t_mlx *mlx, char *map)
{
	int		map_fd;

	map_fd = open(map, O_RDONLY);
	if (map_fd == -1)
	{
		error_log("loading map error!");
		exit(0);
	}
	if (!check_row(map))
	{
		error_log("not a rectangle map!");
		exit(0);
	}

}
