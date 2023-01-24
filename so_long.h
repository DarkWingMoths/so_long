/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:21:47 by mgagnon           #+#    #+#             */
/*   Updated: 2023/01/23 16:48:43 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifdef __linux__ 
#  include "mlx_linux/mlx.h"
#  define UP 119
#  define DOWN 115
#  define LEFT 97
#  define RIGHT 100
#  define ESC 65307
#  define CLOSE
# else
#  include "mlx/mlx.h"
#  define UP 13
#  define DOWN 1
#  define LEFT 0
#  define RIGHT 2
#  define ESC 53
#  define CLOSE 17
# endif

# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_map {
	char	**map;
	char	**map_dup;
	int		coll_nb;
	int		exit_nb;
	int		start_nb;
	int		x_max;
	int		y_max;
	int		ex_x;
	int		ex_y;
	int		exit_check;
}		t_map;

typedef struct s_assets {
	void	*empty;
	void	**wall;
	void	**corn;
	void	*coll;
	void	**play;
	void	**exit;
	int		ass_x;
	int		ass_y;
}		t_assets;

typedef struct s_mlx {
	void		*mlx;
	void		*window;
	int			pos_x;
	int			pos_y;
	int			end_flag;
	int			mov_nb;
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
void	set_origin(t_mlx *mlx);
void	put_outer_wall(t_mlx *mlx);
int		check_action(int key, t_mlx *mlx);
int		end_game(t_mlx *mlx);
int		valid_map(t_mlx *mlx);
void	free_map(char **map, int max_row);
void	store_map(t_mlx *mlx, char *map_dir);
int		check_wall(t_map *map);
int		check_row(t_map *map);

#endif
