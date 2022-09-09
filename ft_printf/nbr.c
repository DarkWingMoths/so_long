/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:43:17 by mgagnon           #+#    #+#             */
/*   Updated: 2022/08/08 11:44:25 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_data *data)
{
	data->count += write(1, &c, 1);
}

void	ft_putnbr(int n, t_data *data)
{
	unsigned int	nbr;

	if (n < 0)
	{
		ft_putchar('-', data);
		nbr = (unsigned int)(n * -1);
	}
	else
		nbr = (unsigned int)n;
	if (nbr >= 10)
		ft_putnbr(nbr / 10, data);
	ft_putchar((char)(nbr % 10 + 48), data);
}

void	ft_putunbr(unsigned int n, t_data *data)
{
	if (n >= 10)
		ft_putunbr(n / 10, data);
	ft_putchar((char)(n % 10 + 48), data);
}

void	ft_putnbr_base_h(t_data *data, unsigned long nbr, char *base)
{
	unsigned int	size_base;

	size_base = ft_strlen(base);
	if (nbr > size_base - 1)
	{
		ft_putnbr_base_h(data, (nbr / size_base), base);
		ft_putnbr_base_h(data, (nbr % size_base), base);
	}
	else
		ft_putchar(base[nbr], data);
}
