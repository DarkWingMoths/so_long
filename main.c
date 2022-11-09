/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:26:49 by mgagnon           #+#    #+#             */
/*   Updated: 2022/11/05 22:10:46 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mlx	*get_data(void)
{
	static t_mlx	*mlx = NULL;

	if (!mlx)
	{
		mlx = ft_calloc(1, sizeof(t_mlx));
		mlx->assets = ft_calloc(1, sizeof(t_assets));
		mlx->assets->wall = ft_calloc(4, sizeof(void));
		mlx->assets->corner = ft_calloc(4, sizeof(void));
		mlx->assets->character = ft_calloc(4, sizeof(void));
	}
	return (mlx);
}

int	main(int ac, char **av)
{
	t_mlx		*mlx;

	check_info(ac, av[1]);
	mlx = get_data();
	mlx->mlx = mlx_init();
	put_map(mlx, av[1]);
	mlx_loop(mlx->mlx);
}
