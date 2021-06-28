/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:52:43 by llalba            #+#    #+#             */
/*   Updated: 2021/06/28 09:25:01 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*former_last;

	if (!new)
		return ;
	if (!(*alst))
		*alst = new;
	else
	{
		former_last = ft_lstlast(*alst);
		former_last->next = new;
	}
}
