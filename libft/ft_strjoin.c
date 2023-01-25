/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:44:21 by mgagnon           #+#    #+#             */
/*   Updated: 2023/01/25 17:11:36 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_str = ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
	if (!new_str)
		return (new_str = ft_sfree(new_str));
	while (len_s1 + len_s2-- > len_s1)
		new_str[len_s1 + len_s2] = s2[len_s2];
	while (len_s1--)
		new_str[len_s1] = s1[len_s1];
	if (*new_str == 0)
		new_str = ft_sfree(new_str);
	return (ft_sfree(s1), new_str);
}
