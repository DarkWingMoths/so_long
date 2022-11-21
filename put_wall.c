/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_wall.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:26:45 by mgagnon           #+#    #+#             */
/*   Updated: 2022/11/21 01:07:59 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "so_long.h"

int	is_corn(int x, int y)
{
	if (x == 0 && y == 0)
		return (0);
	if (x != 0 && y == 0)
		return (1);
	if (x == 0 && y != 0)
		return (2);
	else
		return (3);
}

void	*is_outer(int x, int y, t_mlx *mlx)
{
	if (y == 0)
	{
		if (x == 0 || x == mlx->map->x_max)
			return (mlx->ass->corn[is_corn(x, y)]);
		else
			return (mlx->ass->wall[0]);
	}
	else if (y == mlx->map->y_max)
	{
		if (x == 0 || x == mlx->map->x_max)
			return (mlx->ass->corn[is_corn(x, y)]);
		else
			return (mlx->ass->wall[1]);
	}
	else if (x == 0 && (y != 0 || y != mlx->map->y_max))
		return (mlx->ass->wall[2]);
	else
		return (mlx->ass->wall[3]);
}

void	*put_wall(int x, int y, t_mlx *mlx)
{
	if (x == '0' || x == mlx->map->x_max || y == 0 || y == mlx->map->y_max)
		return (is_outer(x, y, mlx));
	else
		return (mlx->ass->wall[4]);
}
