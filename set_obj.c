/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:33:37 by mgagnon           #+#    #+#             */
/*   Updated: 2022/11/25 18:01:40 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_walls(t_mlx *mlx)
{
	mlx->ass->wall[0] = mlx_xpm_file_to_image(mlx->mlx, \
			"./assets/WallU.xpm", \
			&mlx->ass->ass_x, &mlx->ass->ass_y);
	mlx->ass->wall[1] = mlx_xpm_file_to_image(mlx->mlx, \
			"./assets/WallD.xpm", \
			&mlx->ass->ass_x, &mlx->ass->ass_y);
	mlx->ass->wall[2] = mlx_xpm_file_to_image(mlx->mlx, \
			"./assets/WallL.xpm", \
			&mlx->ass->ass_x, &mlx->ass->ass_y);
	mlx->ass->wall[3] = mlx_xpm_file_to_image(mlx->mlx, \
			"./assets/WallR.xpm", \
			&mlx->ass->ass_x, &mlx->ass->ass_y);
	mlx->ass->wall[4] = mlx_xpm_file_to_image(mlx->mlx, \
			"./assets/WallIN.xpm", \
			&mlx->ass->ass_x, &mlx->ass->ass_y);
	mlx->ass->corn[0] = mlx_xpm_file_to_image(mlx->mlx, \
			"./assets/CornerUL.xpm", \
			&mlx->ass->ass_x, &mlx->ass->ass_y);
	mlx->ass->corn[1] = mlx_xpm_file_to_image(mlx->mlx, \
			"./assets/CornerUR.xpm", \
			&mlx->ass->ass_x, &mlx->ass->ass_y);
	mlx->ass->corn[2] = mlx_xpm_file_to_image(mlx->mlx, \
			"./assets/CornerLL.xpm", \
			&mlx->ass->ass_x, &mlx->ass->ass_y);
	mlx->ass->corn[3] = mlx_xpm_file_to_image(mlx->mlx, \
			"./assets/CornerLR.xpm", \
			&mlx->ass->ass_x, &mlx->ass->ass_y);
}

void	set_player(t_mlx *mlx)
{
	mlx->ass->play[0] = mlx_xpm_file_to_image(mlx->mlx, \
			"./assets/PlayerU.xpm", \
			&mlx->ass->ass_x, &mlx->ass->ass_y);
	mlx->ass->play[1] = mlx_xpm_file_to_image(mlx->mlx, \
			"./assets/PlayerD.xpm", \
			&mlx->ass->ass_x, &mlx->ass->ass_y);
	mlx->ass->play[2] = mlx_xpm_file_to_image(mlx->mlx, \
			"./assets/PlayerL.xpm", \
			&mlx->ass->ass_x, &mlx->ass->ass_y);
	mlx->ass->play[3] = mlx_xpm_file_to_image(mlx->mlx, \
			"./assets/PlayerR.xpm", \
			&mlx->ass->ass_x, &mlx->ass->ass_y);
}

void	set_assets(t_mlx *mlx)
{
	set_walls(mlx);
	set_player(mlx);
	mlx->ass->empty = mlx_xpm_file_to_image(mlx->mlx, \
			"./assets/Empty.xpm", \
			&mlx->ass->ass_x, &mlx->ass->ass_y);
	mlx->ass->coll = mlx_xpm_file_to_image(mlx->mlx, \
			"./assets/Collectible.xpm", \
			&mlx->ass->ass_x, &mlx->ass->ass_y);
	mlx->ass->exit[0] = mlx_xpm_file_to_image(mlx->mlx, \
			"./assets/Exit.xpm", &mlx->ass->ass_x, \
			&mlx->ass->ass_y);
	mlx->ass->exit[1] = mlx_xpm_file_to_image(mlx->mlx, \
			"./assets/Exit_open.xpm", &mlx->ass->ass_x, \
			&mlx->ass->ass_y);
}

void	set_origin(void)
{
	t_mlx	*mlx;
	int		x;
	int		y;

	mlx = get_data();
	y = 0;
	while (y <= mlx->map->y_max)
	{
		x = 0;
		while (x <= mlx->map->x_max)
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
			x++;
		}
		y++;
	}
	printf("variables set :\nstart = %i\npos_x = %i\npos_y = %i\nCollectibles = %i\nexit = %i\n", mlx->map->start_nb, mlx->pos_x, mlx->pos_y, mlx->map->coll_nb, mlx->map->exit_nb);
}
