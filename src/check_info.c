/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:51:16 by mgagnon           #+#    #+#             */
/*   Updated: 2023/01/24 14:36:08 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_type(char *map_dir)
{
	if (!ft_strrchr(map_dir, '.'))
	{
		error_log("Not a file!");
		exit(0);
	}
	map_dir = ft_strrchr(map_dir, '.');
	while (ft_strlen(map_dir) != 4)
	{
		map_dir = ft_strrchr(++map_dir, '.');
	}
	if (ft_strncmp(map_dir, ".ber", 4) != 0)
	{
		error_log("Wrong file type!");
		exit(0);
	}
}

void	check_info(int ac, char *map_dir)
{
	if (ac != 2)
	{
		if (ac > 2)
			error_log("Too much argument!");
		if (ac < 2)
			error_log("Not enough argument!");
		exit(0);
	}
	check_type(map_dir);
}
