/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 11:21:47 by mgagnon           #+#    #+#             */
/*   Updated: 2022/12/07 11:30:22 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef UP
#  ifdef __linux__
#   define UP = 119
#  else
#   define UP = 13
#  endif
# endif

# ifndef DOWN
#  ifdef __linux__
#   define DOWN = 115
#  else
#   define DOWN = 1
#  endif
# endif

# ifndef LEFT
#  ifdef __linux__
#   define LEFT = 97
#  else
#   define LEFT = 0
#  endif
# endif

# ifndef RIGHT
#  ifdef __linux__
#   define RIGHT = 100
#  else
#   define RIGHT = 2
#  endif
# endif

# ifndef ESC
#  ifdef __linux__
#   define ESC = 65307
#  else
#   define ESC = 53
#  endif
# endif

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
	int	ex_x;
	int	ex_y;
	int	exit_check;
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
	unsigned int		mov_nb;
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
int	valid_map(void);

#endif
