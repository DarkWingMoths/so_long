/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:21:47 by mgagnon           #+#    #+#             */
/*   Updated: 2022/11/28 15:15:21 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifdef __linux__ 
#  include "mlx_linux/mlx.h"
# else
#  include "mlx/mlx.h"
# endif
# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_map {
	char	**map;
	int	coll_nb;
	int	exit_nb;
	int	start_nb;
	int	x_max;
	int	y_max;
}		t_map;

typedef struct s_assets {
	void	*empty;
	void	**wall;
	void	**corn;
	void	*coll;
	void	**play;
	void	**exit;
	int	ass_x;
	int	ass_y;
}		t_assets;

typedef struct s_mlx {
	void		*mlx;
	void		*window;
	int		pos_x;
	int		pos_y;
	int		mov_nb;
	int		end_flag;
	t_assets	*ass;
	t_map		*map;
}		t_mlx;

t_mlx	*get_data(void);
void	check_info(int ac, char *map_dir);
void	error_log(char *err_mess);
void	put_map(t_mlx *mlx);
void	check_map(t_mlx *mlx, char *map_dir);
void	clean_exit(t_mlx *mlx, int status);
void	set_assets(t_mlx *mlx);
void	set_origin(void);
void	put_outer_wall(t_mlx *mlx);
int	check_action(int key, t_mlx *mlx);
int	end_game(t_mlx *mlx);

#endif
