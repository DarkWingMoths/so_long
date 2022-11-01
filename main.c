/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:26:49 by mgagnon           #+#    #+#             */
/*   Updated: 2022/10/31 16:00:55 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "so_long.h" */
/* #include "mlx.h" */
#include "mlx_linux/mlx.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	void	*asset_empty;
	int	x;
	int	y;

	x = 32;
	y = 32;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 720, 576, "This is my window");
	asset_empty = mlx_xpm_file_to_image(mlx, "./assets/Empty.xpm", &x, &y);
	mlx_put_image_to_window(mlx, mlx_win, asset_empty, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, asset_empty, 96, 0);
	mlx_loop(mlx);
	(void)mlx_win;
}
