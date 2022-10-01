/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 09:35:57 by mgagnon           #+#    #+#             */
/*   Updated: 2022/05/21 15:36:15 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*proxy;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		proxy = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = proxy;
	}
}
