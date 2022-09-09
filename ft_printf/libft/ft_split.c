/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:43:51 by mgagnon           #+#    #+#             */
/*   Updated: 2022/05/22 15:05:54 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	breakdown(char const *s, char c)
{
	size_t	w;

	w = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
			w++;
		while (*s && *s != c)
			s++;
	}
	return (w);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	len;
	size_t	words;
	char	**tab;

	if (!s)
		return (NULL);
	words = breakdown(s, c);
	tab = ft_calloc(sizeof(char *), (words + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s && *s == c)
			s++;
		if (ft_strchr(s, c))
			len = ft_strchr(s, c) - s;
		else
			len = ft_strlen(s);
		tab[i] = ft_substr(s, 0, len);
		i++;
		s += len;
	}
	return (tab);
}
