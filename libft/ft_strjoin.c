/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:44:21 by mgagnon           #+#    #+#             */
/*   Updated: 2022/11/20 23:59:28 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	new_len;
	/* int		i; */
	/* int		j; */
	
	if (s2[0] != '\n')
		printf("s1 = %s\ns2 = %s\n", s1, s2);
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
	/* i = -1; */
	/* j = 0; */
	/* if (s1) */
	/* 	while (s1[i++] != '\0') */
	/* 		new_str[i] = s1[i]; */
	/* while (s2[j] != '\0') */
	/* 	new_str[i++] = s2[j++]; */
	ft_strlcpy(new_str, (const char *)s1, new_len);
	ft_strlcat(new_str, (const char *)s2, new_len);
	/* new_str[ft_strlen(s1) + ft_strlen(s2)] = '\0'; */
	printf("new_str strjoin = %s\n", new_str);
	if (s1[0] != '\0')
		free(s1);
	return (new_str);
}
