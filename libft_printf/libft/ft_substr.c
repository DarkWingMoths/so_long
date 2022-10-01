/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:48:29 by mgagnon           #+#    #+#             */
/*   Updated: 2022/05/13 18:13:02 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_s;

	if (!s)
		return (NULL);
	if ((int)len > ft_strlen(s))
		len = ft_strlen(s);
	if ((int)start >= ft_strlen(s))
		return (ft_strdup(""));
	new_s = malloc(sizeof (char) * (len + 1));
	if (!new_s)
		return (NULL);
	ft_strlcpy(new_s, &s[start], (len + 1));
	return (new_s);
}
