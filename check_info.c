/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 12:51:16 by mgagnon           #+#    #+#             */
/*   Updated: 2022/11/06 17:02:28 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_type(char *av)
{
	if (!ft_strrchr(av, '.'))
	{
		error_log("Not a file!");
		exit(0);
	}
	av = ft_strrchr(av, '.');
	while(ft_strlen(av) != 4 && !av)
	{
		av = ft_strrchr(++av, '.');
	}
	if (ft_strncmp(av, ".ber", 4) != 0)
	{
		error_log("Wrong file type!");
		exit(0);
	}
}
void	check_info(int ac, char *av)
{
	if (ac != 2)
	{
		if (ac > 2)
			error_log("Too much argument!");
		if (ac < 2)
			error_log("Not enough argument!");
		exit(0);
	}
	check_type(av);
}
