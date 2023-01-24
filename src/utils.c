/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:13:35 by mgagnon           #+#    #+#             */
/*   Updated: 2023/01/24 17:23:03 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	get_next_shish(t_map *map, int map_fd)
{
	char	*tmp;

	tmp = get_next_line(map_fd);
	if (!tmp[0])
	{
		error_log("empty map!");
		free (tmp);
		return (0);
	}
	map->x_max = ft_strlen(tmp) - 2;
	while (tmp)
	{
		if ((ft_strlen(tmp) - 2) != map->x_max)
		{
			error_log("bad map!");
			free(tmp);
			return (0);
		}
		ft_bzero(tmp, ft_strlen(tmp));
		free(tmp);
		tmp = get_next_line(map_fd);
		map->y_max += 1;
	}
	ft_bzero(tmp, ft_strlen(tmp));
	free(tmp);
}
