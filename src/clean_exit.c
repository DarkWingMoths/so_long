/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:36:48 by mgagnon           #+#    #+#             */
/*   Updated: 2023/01/24 17:40:53 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_map(char **map, int max_row)
{
	int	i;

	i = 0;
	while (map[i] != NULL && i <= max_row)
	{
		ft_sfree(map[i]);
		i++;
	}
	ft_sfree(map);
}

void	clean_exit(t_mlx *mlx, int status)
{	
	int	i;

	i = mlx->map->y_max;
	if (mlx->map->map != NULL)
		free_map(mlx->map->map, i);
	if (mlx->window != NULL)
		mlx_destroy_window(mlx->mlx, mlx->window);
	exit(status);
}
