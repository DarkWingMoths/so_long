/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:38:13 by mgagnon           #+#    #+#             */
/*   Updated: 2022/08/08 11:59:27 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_int(t_data *data)
{
	int	arg;

	arg = va_arg(data->args, int);
	ft_putnbr(arg, data);
}

void	print_uint(t_data *data)
{
	unsigned int	arg;

	arg = va_arg(data->args, unsigned int);
	ft_putunbr(arg, data);
}

void	give_address(t_data *data)
{
	unsigned long	arg;

	arg = va_arg(data->args, unsigned long);
	if (!(void *)arg)
		data->count += write(1, "0x0", 3);
	else
	{
		data->count += write(1, "0x", 2);
		ft_putnbr_base_h(data, arg, "0123456789abcdef");
	}
}

void	print_hexa(t_data *data)
{
	unsigned int	arg;

	if (data->format[data->i] == 'x' || data->format[data->i] == 'X')
	{
		arg = va_arg(data->args, unsigned int);
		if (data->format[data->i] == 'X')
			ft_putnbr_base_h(data, arg, "0123456789ABCDEF");
		else
			ft_putnbr_base_h(data, arg, "0123456789abcdef");
	}
	else if (data->format[data->i] == 'p')
		give_address(data);
}

void	give_str(t_data *data)
{
	char	*arg;
	int		index;

	index = 0;
	arg = va_arg(data->args, char *);
	if (arg == NULL)
	{
		data->count += write(1, "(null)", 6);
		return ;
	}
	while (arg[index])
	{
		data->count += write(1, &arg[index], 1);
		index++;
	}
}
