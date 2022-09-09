/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:44:04 by mgagnon           #+#    #+#             */
/*   Updated: 2022/04/22 16:42:48 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	const char	*s2;

	s2 = ft_calloc(1, (ft_strlen(s1) + 1));
	if (!s2)
		return (NULL);
	ft_strlcpy((char *)s2, s1, (ft_strlen(s1) + 1));
	return ((char *)s2);
}
