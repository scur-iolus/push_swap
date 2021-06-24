/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:05:43 by llalba            #+#    #+#             */
/*   Updated: 2021/05/26 11:44:03 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*output;
	t_list	*current;

	if (!f)
		return (0);
	output = 0;
	while (lst)
	{
		current = ft_lstnew((*f)(lst->content));
		if (!current)
		{
			ft_lstclear(&output, del);
			return (0);
		}
		ft_lstadd_back(&output, current);
		lst = lst->next;
	}
	return (output);
}
