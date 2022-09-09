/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:47:53 by mgagnon           #+#    #+#             */
/*   Updated: 2022/05/18 16:45:22 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	newlen;
	size_t	needlen;

	i = 0;
	newlen = ft_strlen(haystack);
	needlen = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)haystack);
	if (len < newlen)
		newlen = len;
	while (i + needlen <= len && newlen--)
	{
		if ((haystack[i] == needle[0])
			&& (ft_strncmp(&haystack[i], needle, needlen) == 0))
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
