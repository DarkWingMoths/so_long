/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:26:49 by mgagnon           #+#    #+#             */
/*   Updated: 2022/11/15 14:06:36 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mlx	*get_data(void)
{
	static t_mlx	*mlx = NULL;

	if (!mlx)
	{
		mlx = ft_calloc(1, sizeof(t_mlx));
		mlx->map = ft_calloc(1, sizeof(t_map));
		mlx->ass = ft_calloc(1, sizeof(t_assets));
		mlx->ass->wall = ft_calloc(5, sizeof(void));
		mlx->ass->corn = ft_calloc(4, sizeof(void));
		mlx->ass->play = ft_calloc(4, sizeof(void));
		mlx->map->coll_nb = 0;
		mlx->map->exit_nb = 0;
		mlx->map->start_nb = 0;
	}
	return (mlx);
}

int	main(int ac, char **av)
{
	t_mlx		*mlx;

	check_info(ac, av[1]);
	mlx = get_data();
	mlx->mlx = mlx_init();
	check_map(mlx, av[1]);
	put_map(mlx);
	mlx_loop(mlx->mlx);
}
