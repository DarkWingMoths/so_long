/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:47:31 by mgagnon           #+#    #+#             */
/*   Updated: 2023/01/22 13:35:14 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*ret;

	index = 0;
	if (!s)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (!ret)
		return (NULL);
	while (s[index] != '\0')
	{
		ret[index] = f(index, s[index]);
		index++;
	}
	ret[index] = '\0';
	return (ret);
}
