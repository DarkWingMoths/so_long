/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:48:03 by mgagnon           #+#    #+#             */
/*   Updated: 2023/01/22 13:25:11 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *s, int c)
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
