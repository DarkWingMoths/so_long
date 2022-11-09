/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:44:21 by mgagnon           #+#    #+#             */
/*   Updated: 2022/04/25 15:43:16 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	new_len;

	if (!s1 || !s2)
		return (NULL);
	new_len = (ft_strlen(s1) + ft_strlen(s2) + 1);
	new_str = malloc(sizeof(char) * new_len);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, new_len);
	ft_strlcat(new_str, s2, new_len);
	return (new_str);
}
