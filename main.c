/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:26:49 by mgagnon           #+#    #+#             */
/*   Updated: 2022/11/22 13:03:45 by mgagnon          ###   ########.fr       */
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
		mlx->map->coll_nb = 0;
		mlx->map->exit_nb = 0;
		mlx->map->start_nb = 0;
	}
	return (mlx);
}

int	main(int ac, char **av)
{
	t_mlx		*mlx;
	int	color_int;

	color_int = 1102884;
	printf("check file\n{\n");
	check_info(ac, av[1]);
	printf("}	check file done\n");
	mlx = get_data();
	mlx->mlx = mlx_init();
	printf("check and stock map\n{\n");
	check_map(mlx, av[1]);
	printf("}	check and stock map done\n");
	put_map(mlx);
	mlx_string_put(mlx->mlx, mlx->window, 20, 20, color_int, "number of movement :");
	mlx_loop(mlx->mlx);
}
