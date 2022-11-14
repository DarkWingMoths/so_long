/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:52:50 by mgagnon           #+#    #+#             */
/*   Updated: 2022/11/14 11:45:22 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
	
void	put_map(t_mlx *mlx)
{
	set_assets(mlx);
	mlx->window = mlx_new_window(mlx->mlx, (mlx->x_max * 64), \
			(mlx->y_max * 64), "so_long mgagnon");
}
