/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:50:40 by mgagnon           #+#    #+#             */
/*   Updated: 2022/08/07 17:43:50 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	char			c;
	char			*s;
	int				di;
	unsigned int	u;
	unsigned int	x;
	void			*p;
	int				result;
	int				my_result;

	c = 104;
	s = "String";
	di = -123456789;
	u = 3004958690;
	x = 34567656;
	p = &x;
//	result = printf("%d", di);
	my_result = ft_printf(" %d ", di);
	printf("\nresult : %d\nmy result : %d\n", result, my_result);
	return (0);
}
