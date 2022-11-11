/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:52:50 by mgagnon           #+#    #+#             */
/*   Updated: 2022/11/10 12:30:28 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
	

void	set_corner(t_mlx *mlx)
{
	mlx->assets->corner[0] = mlx_xpm_file_to_image(mlx->mlx, \
			"./assets/CornerUL.xpm", \
			&mlx->assets->x, &mlx->assets->y);
	mlx->assets->corner[1] = mlx_xpm_file_to_image(mlx->mlx, \
			"./assets/CornerUR.xpm", \
			&mlx->assets->x, &mlx->assets->y);
	mlx->assets->corner[2] = mlx_xpm_file_to_image(mlx->mlx, \
			"./assets/CornerLL.xpm", \
			&mlx->assets->x, &mlx->assets->y);
	mlx->assets->corner[3] = mlx_xpm_file_to_image(mlx->mlx, \
			"./assets/CornerLR.xpm", \
			&mlx->assets->x, &mlx->assets->y);
}

void	set_wall(t_mlx *mlx)
{
	mlx->assets->wall[0] = mlx_xpm_file_to_image(mlx->mlx, \
			"./assets/WallU.xpm", \
			&mlx->assets->x, &mlx->assets->y);
	mlx->assets->corner[1] = mlx_xpm_file_to_image(mlx->mlx, \
			"./assets/WallD.xpm", \
			&mlx->assets->x, &mlx->assets->y);
	mlx->assets->corner[2] = mlx_xpm_file_to_image(mlx->mlx, \
			"./assets/WallL.xpm", \
			&mlx->assets->x, &mlx->assets->y);
	mlx->assets->corner[3] = mlx_xpm_file_to_image(mlx->mlx, \
			"./assets/WallR.xpm", \
			&mlx->assets->x, &mlx->assets->y);
}

void	set_assets(t_mlx *mlx)
{
	mlx->assets->empty = mlx_xpm_file_to_image(mlx->mlx, \
			"./assets/Empty.xpm", \
			&mlx->assets->x, &mlx->assets->y);
	set_wall(mlx);
	set_corner(mlx);
	/* mlx->assets->collectible = mlx_xpm_file_to_image(mlx->mlx, \ */
	/* 		"./assets/Collectible.xpm", \ */
	/* 		&mlx->assets->x, &mlx->assets->y); */
	mlx->assets->character[0] = mlx_xpm_file_to_image(mlx->mlx, \
			"./assets/Character.xpm", \
			&mlx->assets->x, &mlx->assets->y);
	/* mlx->assets->character[1] = mlx_xpm_file_to_image(mlx->mlx, \ */
	/* 		"./assets/Character_down.xpm", \ */
	/* 		&mlx->assets->x, &mlx->assets->y); */
	/* mlx->assets->character[2] = mlx_xpm_file_to_image(mlx->mlx, \ */
	/* 		"./assets/Character_left.xpm", \ */
	/* 		&mlx->assets->x, &mlx->assets->y); */
	/* mlx->assets->character[3] = mlx_xpm_file_to_image(mlx->mlx, \ */
	/* 		"./assets/Character_right.xpm", \ */
	/* 		&mlx->assets->x, &mlx->assets->y); */
}

void	put_map(t_mlx *mlx, char *map)
{
	int	x;
	int	y = 0;

	(void)map;
	set_assets(mlx);
	mlx->x_win = 384;
	mlx->y_win = 384;
	mlx->window = mlx_new_window(mlx->mlx, mlx->x_win, \
			mlx->y_win, "so_long mgagnon");
	while (y <= 320)
	{
		x = 0;
		printf("In Y loop\n");
		while (x <= 320)
		{
			printf("In X loop\n");
			if (x == 0 && y == 0)
			{
				mlx_put_image_to_window(mlx->mlx, mlx->window, \
						mlx->assets->corner[0], x, y);
				printf("UL corner\n");
			}
			else if (x == 320 && y == 0)
			{
				mlx_put_image_to_window(mlx->mlx, mlx->window, \
						mlx->assets->corner[1], x, y);
				printf("UR corner\n");
			}
			else if (x == 0 && y == 320)
			{
				mlx_put_image_to_window(mlx->mlx, mlx->window, \
						mlx->assets->corner[2], x, y);
				printf("LL corner\n");
			}
			else if (x == 320 && y == 320)
			{
				mlx_put_image_to_window(mlx->mlx, mlx->window, \
						mlx->assets->corner[3], x, y);
				printf("LR corner\n");
			}
			else if (y == 0 && x != 0 && x != 320)
			{
				mlx_put_image_to_window(mlx->mlx, mlx->window, \
						mlx->assets->wall[0], x, y);
				printf("U wall\n");
			}
			else if (y == 320 && x != 0 && x != 320)
			{
				mlx_put_image_to_window(mlx->mlx, mlx->window, \
					mlx->assets->wall[1], x, y);
				printf("D wall\n");
			}
			else if (x == 0 && y != 0 && y != 320)
			{
				mlx_put_image_to_window(mlx->mlx, mlx->window, \
					mlx->assets->wall[2], x, y);
				printf("L wall\n");
			}
			else if (x == 320 && y != 0 && y != 320)
			{
				mlx_put_image_to_window(mlx->mlx, mlx->window, \
					mlx->assets->wall[3], x, y);
				printf("R wall\n");
			}
			else
			{
				mlx_put_image_to_window(mlx->mlx, mlx->window, \
					mlx->assets->empty, x, y);
				printf("empty\n");
			}
			x += 64;
		}
		y += 64;
	}
	/* mlx_put_image_to_window(mlx->mlx, mlx->window, \ */
	/* 		mlx->assets->wall, 32, 0); */
	/* mlx_put_image_to_window(mlx->mlx, mlx->window, \ */
	/* 		mlx->assets->empty, 32, 32); */
	/* mlx_put_image_to_window(mlx->mlx, mlx->window, \ */
	/* 		mlx->assets->wall, 0, 32); */
}
