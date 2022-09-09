/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 09:33:06 by mgagnon           #+#    #+#             */
/*   Updated: 2022/05/21 15:02:07 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*proxy;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			proxy = ft_lstlast(*(lst));
			proxy->next = new;
		}
	}
}
