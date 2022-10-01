/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:43:57 by mgagnon           #+#    #+#             */
/*   Updated: 2022/05/18 16:46:58 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*chstr;

	c %= 256;
	chstr = (char *)s;
	while (*chstr != c)
	{
		if (*chstr == '\0')
			return (NULL);
		chstr++;
	}
	return (chstr);
}
