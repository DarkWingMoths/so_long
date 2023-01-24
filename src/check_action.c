/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:11:37 by mgagnon           #+#    #+#             */
/*   Updated: 2023/01/24 17:06:52 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_old(t_mlx *mlx)
{
	if (mlx->map->map[mlx->pos_y][mlx->pos_x] == 'E')
		mlx_put_image_to_window(mlx->mlx, mlx->window, \
				mlx->ass->exit[0], mlx->pos_x * 64, mlx->pos_y * 64);
	else
		mlx_put_image_to_window(mlx->mlx, mlx->window, \
				mlx->ass->empty, mlx->pos_x * 64, mlx->pos_y * 64);
}

void	print_new(t_mlx *mlx, void *base, int dir)
{
	if (dir == 0)
		move_up(mlx, base);
	else if (dir == 1)
		move_down(mlx, base);
	else if (dir == 2)
		move_left(mlx, base);
	else if (dir == 3)
		move_right(mlx, base);
}

void	do_act(t_mlx *mlx, int dir, int x, int y)
{
	char	new_pos;

	print_old(mlx);
	new_pos = mlx->map->map[mlx->pos_y + y][mlx->pos_x + x];
	if (new_pos == 'C')
		do_collectible(mlx, dir, x, y);
	else if (new_pos == 'E')
	{
		do_exit(mlx, dir, x, y);
		return ;
	}
	else if (new_pos == '1')
	{
		do_wall(mlx, dir, x, y);
		return ;
	}
	print_new(mlx, mlx->ass->empty, dir);
	mlx->pos_x += x;
	mlx->pos_y += y;
	mlx->mov_nb++;
}

int	get_dir(int key)
{
	if (key == UP)
		return (0);
	else if (key == DOWN)
		return (1);
	else if (key == LEFT)
		return (2);
	else if (key == RIGHT)
		return (3);
	return (10);
}

int	check_action(int key, t_mlx *mlx)
{
	int	x;
	int	y;
	int	dir;

	x = 0;
	y = 0;
	if (key == ESC)
		clean_exit(mlx, 0);
	dir = get_dir(key);
	if (dir == 0)
		y = -1;
	else if (dir == 1)
		y = 1;
	else if (dir == 2)
		x = -1;
	else if (dir == 3)
		x = 1;
	if (dir != 10)
		do_act(mlx, dir, x, y);
	printf("\rnumber of move = %u\n", mlx->mov_nb);
	return (0);
}
