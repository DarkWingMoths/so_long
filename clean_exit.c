/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:36:48 by mgagnon           #+#    #+#             */
/*   Updated: 2022/11/14 09:32:18 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	clean_assets(t_assets *ass)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		ft_memset(ass->wall[i], '\0', ft_strlen(ass->wall[i]));
		ft_memset(ass->corn[i], '\0', ft_strlen(ass->corn[i]));
		ft_memset(ass->play[i], '\0', ft_strlen(ass->play[i]));
		i++;
	}
}
void	clean_exit(t_mlx *mlx)
{
	
}
