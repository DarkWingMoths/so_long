/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:46:23 by mgagnon           #+#    #+#             */
/*   Updated: 2023/01/25 17:12:19 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		ft_putstr_fd(map[i], 1);
		i++;
	}
}
