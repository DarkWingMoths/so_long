/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 12:03:03 by mgagnon           #+#    #+#             */
/*   Updated: 2022/11/18 12:37:21 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_map(void)
{
	t_mlx	*mlx;

	mlx = get_data();
	if (mlx->map->exit_nb != 1 || mlx->map->start_nb != 1 || \
			mlx->map->coll_nb == 0)
	{
		error_log("invalid map!");
		clean_exit(mlx, 0);
	}
}
