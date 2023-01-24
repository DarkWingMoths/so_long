/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:36:48 by mgagnon           #+#    #+#             */
/*   Updated: 2023/01/23 17:56:36 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map, int max_row)
{
	int	i;

	i = 0;
	while (map[i] != NULL && i <= max_row)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	clean_exit(t_mlx *mlx, int status)
{	
	int	i;

	/* free(mlx->ass->wall); */
	/* free(mlx->ass->corn); */
	/* free(mlx->ass->play); */
	/* free(mlx->ass->exit); */
	/* free(mlx->ass); */
	i = mlx->map->y_max;
	free_map(mlx->map->map, i);
	free(mlx);
	mlx_destroy_window(mlx->mlx, mlx->window);
	exit(status);
}
