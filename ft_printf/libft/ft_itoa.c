/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:41:38 by mgagnon           #+#    #+#             */
/*   Updated: 2022/05/21 18:29:02 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_unit_count(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = n * -1;
		count++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	ft_putnbr(long n, int *i, char *str)
{
	if (n > 9)
	{
		ft_putnbr(n / 10, i, str);
		ft_putnbr(n % 10, i, str);
	}
	else
		str[(*i)++] = n + '0';
}

char	*ft_itoa(int n)
{
	char	*conv_char;
	int		i;
	long	nb;

	nb = n;
	i = 0;
	conv_char = ft_calloc(sizeof (char), (ft_unit_count(nb) + 1));
	if (!conv_char)
		return (NULL);
	if (nb < 0)
	{
		conv_char[i++] = '-';
		nb *= -1;
	}
	ft_putnbr(nb, &i, conv_char);
	return (conv_char);
}
