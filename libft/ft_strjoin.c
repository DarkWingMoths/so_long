/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:44:21 by mgagnon           #+#    #+#             */
/*   Updated: 2022/11/23 10:27:32 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	new_len;
	/* int		i; */
	/* int		j; */
	
	if (!s1)
	{
		s1 = (char *)ft_calloc(1, sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	new_len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	new_str = ft_calloc(new_len ,sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, (const char *)s1, new_len);
	ft_strlcat(new_str, (const char *)s2, new_len);
	if (s1[0] != '\0')
		free(s1);
	return (new_str);
}
