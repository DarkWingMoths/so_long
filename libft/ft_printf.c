/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:55:23 by mgagnon           #+#    #+#             */
/*   Updated: 2022/10/26 16:23:16 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	get_args(t_data *data)
{
	char	c;

	if (data->format[data->i] == 'c')
	{
		c = va_arg(data->args, int);
		data->count += write(1, &c, 1);
	}
	else if (data->format[data->i] == '%')
	{
		c = 37;
		data->count += write(1, &c, 1);
	}
	else if (data->format[data->i] == 's')
		give_str(data);
	else if (data->format[data->i] == 'd' || data->format[data->i] == 'i')
		print_int(data);
	else if (data->format[data->i] == 'u')
		print_uint(data);
	else if (data->format[data->i] == 'x' || data->format[data->i] == 'X'
		|| data->format[data->i] == 'p')
		print_hexa(data);
}

int	ft_printf(const char *format, ...)
{
	t_data	*data;
	int		count;

	data = calloc(1, sizeof(t_data));
	data->format = format;
	va_start(data->args, format);
	while (data->format[data->i])
	{
		if (data->format[data->i] == '%')
		{
			data->i++;
			get_args(data);
		}
		else
			data->count += write(1, &data->format[data->i], 1);
		data->i++;
	}
	va_end(data->args);
	count = data->count;
	free(data);
	return (count);
}
