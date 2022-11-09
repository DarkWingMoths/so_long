/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:48:17 by mgagnon           #+#    #+#             */
/*   Updated: 2022/05/18 16:47:17 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	index;
	size_t	s1_len;

	if (!s1 || !set)
		return (NULL);
	s1_len = ft_strlen(s1);
	index = 0;
	while (ft_strchr(set, (int)s1[index]) && index < s1_len)
			index++;
	while (ft_strchr(set, (int)s1[s1_len]) && s1_len > index)
		s1_len--;
	return (ft_substr(s1, (unsigned int)index, (s1_len - index + 1)));
}
