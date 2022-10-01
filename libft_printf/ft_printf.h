/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:35:21 by mgagnon           #+#    #+#             */
/*   Updated: 2022/08/18 20:07:28 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_data
{
	int			count;
	va_list		args;
	int			i;
	const char	*format;
}				t_data;

int		ft_printf(const char *format, ...);
void	get_args(t_data *data);
void	give_address(t_data *data);
void	give_nbr(t_data *data);
void	give_str(t_data *data);
void	ft_putnbr_base_h(t_data *data, unsigned long nbr, char *base);
void	ft_putnbr(int n, t_data *data);
void	ft_putchar(char c, t_data *data);
void	print_int(t_data *data);
void	print_uint(t_data *data);
void	ft_putunbr(unsigned int n, t_data *data);
void	print_hexa(t_data *data);

#endif
