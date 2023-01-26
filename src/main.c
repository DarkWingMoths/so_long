/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:26:49 by mgagnon           #+#    #+#             */
/*   Updated: 2023/01/25 23:17:47 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	end_game(t_mlx *mlx)
{
	printf("final move count = %u\n", mlx->mov_nb);
	clean_exit(mlx, 0);
	return (0);
}

void	store_map(t_mlx *mlx, char *map)
{
	int	i;
	int	map_fd;

	i = 0;
	map_fd = open(map, O_RDONLY);
	if (map_fd == -1)
	{
		error_log("loading map!");
		close(map_fd);
		clean_exit(mlx, 1);
	}
	mlx->map->map = ft_calloc(sizeof(char *), (mlx->map->y_max + 1));
	if (!mlx->map->map)
		clean_exit(mlx, 1);
	while (i <= mlx->map->y_max)
	{
		mlx->map->map[i] = get_next_line(map_fd);
		i++;
	}
	close(map_fd);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;
	char	*str;

	check_info(ac, av[1]);
	mlx.mlx = mlx_init();
	check_map(&mlx, av[1]);
	store_map(&mlx, av[1]);
	if (!check_wall(mlx.map))
		clean_exit(&mlx, 1);
	if (!check_row(mlx.map))
		clean_exit(&mlx, 1);
	set_origin(&mlx);
	if (!valid_map(&mlx))
		clean_exit(&mlx, 1);
	put_map(&mlx);
	/* mlx_hook(mlx.window, CLOSE, 0L, end_game, &mlx); */
	mlx_key_hook(mlx.window, check_action, &mlx);
	mlx_loop_hook(mlx.mlx, &anim_coll, &mlx); 
	mlx_loop(&mlx.mlx);
}
