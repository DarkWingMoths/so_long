/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:26:49 by mgagnon           #+#    #+#             */
/*   Updated: 2022/11/30 13:32:48 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_game(t_mlx *mlx)
{
	/* mlx_destroy_window(mlx->mlx, mlx->window); */
	clean_exit(mlx->mlx, 1);
	return (0);
}

t_mlx	*get_data(void)
{
	static t_mlx	*mlx = NULL;

	if (!mlx)
	{
		mlx = ft_calloc(1, sizeof(t_mlx));
		mlx->ass = ft_calloc(1, sizeof(t_assets));
		mlx->ass->wall = ft_calloc(5, sizeof(void *));
		mlx->ass->play = ft_calloc(4, sizeof(void *));
		mlx->ass->corn = ft_calloc(4, sizeof(void *));
		mlx->ass->exit = ft_calloc(2, sizeof(void *));
		mlx->map = ft_calloc(1, sizeof(t_map));
		mlx->map->coll_nb = 0;
		mlx->map->exit_nb = 0;
		mlx->map->start_nb = 0;
		mlx->end_flag = 0;
	}
	return (mlx);
}

int	main(int ac, char **av)
{
	t_mlx		*mlx;
	int	color_int;

	color_int = 1102884;
	check_info(ac, av[1]);
	mlx = get_data();
	mlx->mlx = mlx_init();
	check_map(mlx, av[1]);
	put_map(mlx);
	mlx_string_put(mlx->mlx, mlx->window, 20, 20, color_int, "number of movement :");
	mlx_hook(mlx->window, 17, 0L, end_game, mlx); 
	/* mlx_key_hook(mlx->window, check_action, mlx); */
	mlx_loop(mlx->mlx);
}
