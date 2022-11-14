/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:21:47 by mgagnon           #+#    #+#             */
/*   Updated: 2022/11/13 18:50:52 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "mlx_linux/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_assets {
	void	*empty;
	void	**wall;
	void	**corn;
	void	*coll;
	void	**play;
	void	*exit;
	int	x;
	int	y;
}		t_assets;

typedef struct s_mlx {
	void		*mlx;
	void		*window;
	char		**map;
	int		x_max;
	int		y_max;
	int		pos_x;
	int		pos_y;
	t_assets	*ass;
}		t_mlx;

t_mlx	*get_data(void);
void	check_info(int ac, char *av);
void	error_log(char *err_mess);
void	put_map(t_mlx *mlx, char *map);
void	check_map(t_mlx *mlx, char *map);
void	clean_exit(t_mlx *mlx);

#endif
