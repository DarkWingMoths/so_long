/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   act_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:46:01 by mgagnon           #+#    #+#             */
/*   Updated: 2023/01/25 10:54:49 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	do_wall(t_mlx *mlx, int dir, int x, int y)
{
	if (mlx->map->map[mlx->pos_y][mlx->pos_x] == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->window, \
				mlx->ass->exit[0], mlx->pos_x * 64, mlx->pos_y * 64);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->window, \
				mlx->ass->empty, mlx->pos_x * 64, mlx->pos_y * 64);
	mlx_put_image_to_window(mlx->mlx, mlx->window, \
			mlx->ass->play[dir], mlx->pos_x * 64, mlx->pos_y * 64);
}

void	do_exit(t_mlx *mlx, int dir, int x, int y)
{
	if (mlx->end_flag == 1)
	{
		print_new(mlx, mlx->ass->exit[1], dir);
		mlx->mov_nb++;
		end_game(mlx);
	}
	else
		print_new(mlx, mlx->ass->exit[0], dir);
	mlx->pos_x += x;
	mlx->pos_y += y;
	mlx->mov_nb++;
}

void	do_collectible(t_mlx *mlx, int dir, int x, int y)
{
	mlx->map->map[mlx->pos_y + y][mlx->pos_x + x] = '0';
	mlx->map->coll_nb--;
	if (mlx->map->coll_nb == 0)
	{
		mlx->end_flag = 1;
		mlx_put_image_to_window(mlx->mlx, mlx->window, \
				mlx->ass->exit[1], mlx->map->ex_x * 64, mlx->map->ex_y * 64);
	}
}
