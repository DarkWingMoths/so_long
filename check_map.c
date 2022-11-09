/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:03:27 by mgagnon           #+#    #+#             */
/*   Updated: 2022/11/08 15:08:41 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_column(t_mlx *mlx, char *map)
{
	char	*tmp;
	char	*tmp_2;
}

void	check_row(t_mlx *mlx, char *map)
{
	char	*tmp;
	char	*tmp_2;
}

void	check_map(t_mlx *mlx, char *map)
{
	int		map_fd;
	int		counter;

	map_fd = open(map, O_RDONLY);
	if (map_fd == -1)
	{
		error_log("loading map error!");
		exit(0);
	}
	counter = 0;
	while (tmp != NULL || tmp_2 != NULL)
	{
		tmp = get_next_line(map_fd);
		tmp_2 = get_next_line(map_fd);
		if (ft_strlen(tmp) != ft_strlen(tmp_2))
		{
			error_log("not a rectangle map!");
			exit(0);
		}
		counter++;
	}
}
