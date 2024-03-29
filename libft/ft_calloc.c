/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:40:20 by mgagnon           #+#    #+#             */
/*   Updated: 2023/01/25 17:10:10 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	ret = malloc(count * size);
	if (!ret)
	{
		free(ret);
		return (NULL);
	}
	if (count == SIZE_MAX || size == SIZE_MAX || ret == NULL)
		return (NULL);
	ft_bzero(ret, (count * size));
	return (ret);
}
