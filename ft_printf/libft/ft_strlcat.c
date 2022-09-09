/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:30:13 by mgagnon           #+#    #+#             */
/*   Updated: 2022/05/13 17:46:52 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	len_dest;
	size_t	i_src;
	size_t	ret;

	len_dest = ft_strlen(dest);
	i_src = 0;
	ret = len_dest + ft_strlen(src);
	if (len_dest >= destsize)
		return (destsize + ft_strlen(src));
	while (((len_dest + i_src) < (destsize - 1)) && src[i_src])
	{
		dest[i_src + len_dest] = src[i_src];
		i_src++;
	}
	dest[i_src + len_dest] = '\0';
	return (ret);
}
