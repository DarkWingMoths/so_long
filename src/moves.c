/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:58:35 by mgagnon           #+#    #+#             */
/*   Updated: 2023/01/24 17:44:09 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_up(t_mlx *mlx, void *base)
{
	mlx_put_image_to_window(mlx->mlx, mlx->window, base, \
			mlx->pos_x * 64, (mlx->pos_y - 1) * 64);
	mlx_put_image_to_window(mlx->mlx, mlx->window, \
			mlx->ass->play[0], mlx->pos_x * 64, \
			(mlx->pos_y - 1) * 64);
}

void	move_down(t_mlx *mlx, void *base)
{
	mlx_put_image_to_window(mlx->mlx, mlx->window, base, \
			mlx->pos_x * 64, (mlx->pos_y + 1) * 64);
	mlx_put_image_to_window(mlx->mlx, mlx->window, \
			mlx->ass->play[1], mlx->pos_x * 64, \
			(mlx->pos_y + 1) * 64);
}

void	move_left(t_mlx *mlx, void *base)
{
	mlx_put_image_to_window(mlx->mlx, mlx->window, base, \
			(mlx->pos_x - 1) * 64, mlx->pos_y * 64);
	mlx_put_image_to_window(mlx->mlx, mlx->window, \
			mlx->ass->play[2], (mlx->pos_x - 1) * 64, \
			mlx->pos_y * 64);
}

void	move_right(t_mlx *mlx, void *base)
{
	mlx_put_image_to_window(mlx->mlx, mlx->window, base, \
			(mlx->pos_x + 1) * 64, mlx->pos_y * 64);
	mlx_put_image_to_window(mlx->mlx, mlx->window, \
			mlx->ass->play[3], (mlx->pos_x + 1) * 64, \
			mlx->pos_y * 64);
}
