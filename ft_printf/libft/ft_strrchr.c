/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:48:03 by mgagnon           #+#    #+#             */
/*   Updated: 2022/05/18 16:45:49 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	c %= 256;
	len = ft_strlen(s);
	while ((s[len] != c) && (len > 0))
		len--;
	if (s[len] == c)
		return ((char *)&s[len]);
	return (NULL);
}
