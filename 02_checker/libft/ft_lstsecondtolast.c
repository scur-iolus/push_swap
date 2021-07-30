/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsecondtolast.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:05:32 by llalba            #+#    #+#             */
/*   Updated: 2021/06/28 09:32:14 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstsecondtolast(t_list *lst)
{
	t_list	*current;
	t_list	*previous;

	if (!lst || !lst->next)
		return (0);
	current = lst;
	while (current->next)
	{
		previous = current;
		current = current->next;
	}
	return (previous);
}
