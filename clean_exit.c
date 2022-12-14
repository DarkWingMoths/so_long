/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:36:48 by mgagnon           #+#    #+#             */
/*   Updated: 2023/01/04 19:27:29 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_image(t_mlx *mlx)
{
	int	i;

	mlx_destroy_image(mlx->mlx, mlx->ass->coll);
	i = 0;
	while (i < 2)
	{
		mlx_destroy_image(mlx->mlx, mlx->ass->exit[i]);
		mlx_destroy_image(mlx->mlx, mlx->ass->corn[i]);
		mlx_destroy_image(mlx->mlx, mlx->ass->play[i]);
		mlx_destroy_image(mlx->mlx, mlx->ass->wall[i]);
		i++;
	}
	while (i < 4)
	{
		mlx_destroy_image(mlx->mlx, mlx->ass->corn[i]);
		mlx_destroy_image(mlx->mlx, mlx->ass->play[i]);
		mlx_destroy_image(mlx->mlx, mlx->ass->wall[i]);
		i++;
	}
	mlx_destroy_image(mlx->mlx, mlx->ass->wall[i]);
}

void	clean_exit(t_mlx *mlx, int status)
{	
	int	i;

	destroy_image(mlx);
	free(mlx->ass->wall);
	free(mlx->ass->corn);
	free(mlx->ass->play);
	free(mlx->ass->exit);
	free(mlx->ass);
	i = mlx->map->y_max;
	while (i >= 0)
	{
		if (mlx->map->map[i] != NULL)
			ft_bzero(mlx->map->map[i], ft_strlen(mlx->map->map[i]));
		free(mlx->map->map[i]);
		i--;
	}
	free(mlx->map);
	free(mlx);
	mlx_destroy_window(mlx->mlx, mlx->window);
	exit(status);
}
