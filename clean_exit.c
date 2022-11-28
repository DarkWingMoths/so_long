/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:36:48 by mgagnon           #+#    #+#             */
/*   Updated: 2022/11/27 03:36:31 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_exit(t_mlx *mlx, int status)
{	
	int	i;

	i = mlx->map->y_max;
	while (i >= 0)
	{
		if (mlx->map->map[i])
			ft_bzero(mlx->map->map[i], ft_strlen(mlx->map->map[i]));
		i--;
	}
	free(mlx->map);
	free(mlx->ass);
	free(mlx);
	exit(status);
}
