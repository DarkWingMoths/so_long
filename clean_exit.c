/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:36:48 by mgagnon           #+#    #+#             */
/*   Updated: 2022/11/14 12:57:48 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_assets(t_assets *ass)
{
	int	i;

	i = 4;
	while (i-- >= 0)
	{
		if (ass->wall[i])
			ft_bzero(ass->wall[i], ft_strlen(ass->wall[i]));
		if (ass->corn[i])
			ft_bzero(ass->corn[i], ft_strlen(ass->corn[i]));
		if (ass->play[i])
			ft_bzero(ass->play[i], ft_strlen(ass->play[i]));
	}
	free(ass->wall);
	free(ass->corn);
	free(ass->play);
}

void	clean_exit(t_mlx *mlx, int status)
{	
	int	i;

	i = mlx->x_max;
	clean_assets(mlx->ass);
	free(mlx->ass);
	while (i >= 0)
	{
		if (mlx->map[i])
			ft_bzero(mlx->map[i], ft_strlen(mlx->map[i]));
		i--;
	}
	free(mlx->ass);
	free(mlx);
	exit(status);
}
