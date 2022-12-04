/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:11:37 by mgagnon           #+#    #+#             */
/*   Updated: 2022/12/03 20:35:32 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	{
		mlx_put_image_to_window(mlx->mlx, mlx->window, base, \
				mlx->pos_x * 64, (mlx->pos_y - 1) * 64);
		mlx_put_image_to_window(mlx->mlx, mlx->window, \
				mlx->ass->play[dir], mlx->pos_x * 64, \
				(mlx->pos_y - 1) * 64);
	}
	else if (dir == 1)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->window, base, \
				mlx->pos_x * 64, (mlx->pos_y + 1) * 64);
		mlx_put_image_to_window(mlx->mlx, mlx->window, \
				mlx->ass->play[dir], mlx->pos_x * 64, \
				(mlx->pos_y + 1) * 64);
	}
	else if (dir == 2)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->window, base, \
				(mlx->pos_x - 1) * 64, mlx->pos_y * 64);
		mlx_put_image_to_window(mlx->mlx, mlx->window, \
				mlx->ass->play[dir], (mlx->pos_x - 1) * 64, \
				mlx->pos_y * 64);
	}
	else if (dir == 3)
	{
		mlx_put_image_to_window(mlx->mlx, mlx->window, base, \
				(mlx->pos_x + 1) * 64, mlx->pos_y * 64);
		mlx_put_image_to_window(mlx->mlx, mlx->window, \
				mlx->ass->play[dir], (mlx->pos_x + 1) * 64, \
				mlx->pos_y * 64);
	}
}

void	do_act(t_mlx *mlx, int dir, int x, int y)
{
	char	new_pos;

	new_pos = mlx->map->map[mlx->pos_y + y][mlx->pos_x + x];
	if (new_pos == 'C')
	{
		mlx->map->coll_nb--;
		if (mlx->map->coll_nb == 0)
		{
			mlx->end_flag = 1;
			mlx_put_image_to_window(mlx->mlx, mlx->window, \
					mlx->ass->exit[1], mlx->map->ex_x * \
					64, mlx->map->ex_y * 64);
		}
		new_pos = '0';
	}
	else if (new_pos == 'E')
	{
		print_old(mlx);
		print_new(mlx, mlx->ass->exit[0], dir);
		if (mlx->end_flag == 1)
			end_game(mlx);
		return;
	}
	else if (new_pos == '1')
	{
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->ass->empty, mlx->pos_x * 64, mlx->pos_y * 64);
		mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->ass->play[dir], mlx->pos_x * 64, mlx->pos_y * 64);
		return;
	}
	print_old(mlx);
	print_new(mlx, mlx->ass->empty, dir);
}

int	get_dir(int key)
{
	/* if (key == 13 || key == 126) MacOS*/
	/* 	return (0);*/
	/* else if (key == 1 || key == 125) MacOS*/
	/* 	return (1);*/
	/* else if (key == 0 || key == 123) MacOS*/
	/* 	return (2);*/
	/* else if (key == 2 || key == 124) MacOS*/
	/* 	return (3);*/
	if (key == 119 || key == 65362) /*LINUX*/
		return (0);
	else if (key == 115 || key == 65364) /*LINUX*/
		return (1);
	else if (key == 97 || key == 65361) /*LINUX*/
		return (2);
	else if (key == 100 || key == 65363) /*LINUX*/
		return (3);
	else
		return (10);
}

int	check_action(int key, t_mlx *mlx)
{
	int	x;
	int	y;
	int	dir;

	x = 0;
	y = 0;
	if (key == 65307) /*LINUX*/
		clean_exit(mlx, 1); 
	/* if (key == 53) MacOS*/
	/* 	clean_exit(mlx, 1);*/
	dir = get_dir(key);
	if (dir == 0)
		y = -1;
	else if (dir == 1)
		y = 1;
	else if (dir == 2)
		x = -1;
	else if (dir == 3)
		x = 1;
	do_act(mlx, dir, x, y);
	mlx->pos_x += x;
	mlx->pos_y += y;
	return (0);
}
