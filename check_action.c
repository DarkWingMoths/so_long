/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 12:11:37 by mgagnon           #+#    #+#             */
/*   Updated: 2022/11/27 23:22:37 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

void	do_act(int x, int y, t_mlx *mlx)
{
	char	new_pos;

	new_pos = mlx->map->map[mlx->pos_y + y][mlx->pos_x + x];
	if (new_pos == 'C')
		mlx->map->coll_nb--;
	else if (new_pos == 'E')
}

int	get_dir(int key)
{
	if (key == 119 || key == 65362)
		return (0);
	else if (key == 115 || key == 65364)
		return (1);
	else if (key == 97 || key == 65361)
		return (2);
	else if (key == 100 || key == 65363)
		return (3);
}

int	check_action(int key, t_mlx *mlx)
{
	int	x;
	int	y;
	int	dir;

	x = 0;
	y = 0;
	dir = get_dir(key);
	if (key == 65307)
		clean_exit(mlx, 1);
	if (mlx->map->map[mlx->pos_y + y][mlx->pos_x + x] == '1')
		return (0);
	else
		do_act(x, y, mlx);
	mlx->pos_x += x;
	mlx->pos_y += y;
	return (0);
}
