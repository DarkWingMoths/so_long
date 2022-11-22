/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:33:37 by mgagnon           #+#    #+#             */
/*   Updated: 2022/11/22 10:26:48 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_assets(t_mlx *mlx)
{
	mlx->empty = mlx_xpm_file_to_image(mlx->mlx, \
			"./assets/Empty.xpm", \
			&mlx->ass_x, &mlx->ass_y);
	mlx->wall = mlx_xpm_file_to_image(mlx->mlx, \
			"./assets/WallIN.xpm", \
			&mlx->ass_x, &mlx->ass_y);
	mlx->play = mlx_xpm_file_to_image(mlx->mlx, \
			"./assets/PlayerR.xpm", \
			&mlx->ass_x, &mlx->ass_y);
	mlx->coll = mlx_xpm_file_to_image(mlx->mlx, \
			"./assets/Collectible.xpm", \
			&mlx->ass_x, &mlx->ass_y);
	mlx->exit = mlx_xpm_file_to_image(mlx->mlx, \
			"./assets/Exit.xpm", &mlx->ass_x, \
			&mlx->ass_y);
}

void	set_origin(void)
{
	t_mlx	*mlx;
	int		x;
	int		y;

	mlx = get_data();
	x = 0;
	y = 0;
	while (mlx->map->map[y])
	{
		while (mlx->map->map[y][x])
		{
			if (mlx->map->map[y][x] == 'P')
			{
				mlx->pos_x = x;
				mlx->pos_y = y;
				mlx->map->start_nb++;
			}
			else if (mlx->map->map[y][x] == 'C')
				mlx->map->coll_nb++;
			else if (mlx->map->map[y][x] == 'E')
				mlx->map->exit_nb++;
		}
		x++;
	}
	y++;
}
