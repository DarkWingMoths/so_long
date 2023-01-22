/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:44:04 by mgagnon           #+#    #+#             */
/*   Updated: 2023/01/22 13:29:44 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s1)
{
	char	*s2;

	s2 = ft_calloc((ft_strlen(s1) + 1), 1);
	if (!s2)
	{
		free(s2);
		return (NULL);
	}
	ft_strlcpy((char *)s2, s1, (ft_strlen(s1) + 1));
	return ((char *)s2);
}
