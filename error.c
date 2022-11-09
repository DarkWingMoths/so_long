/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:18:06 by mgagnon           #+#    #+#             */
/*   Updated: 2022/11/05 08:34:55 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

void	error_log(char *err_mess)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(err_mess, 1);
	write(1, "\n", 1);
}
