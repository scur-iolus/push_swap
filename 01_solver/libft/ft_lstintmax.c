/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstintmax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 15:55:49 by llalba            #+#    #+#             */
/*   Updated: 2021/08/01 14:08:02 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstintmax(t_list *a)
{
	t_list	*tmp;
	t_list	*node;

	tmp = a;
	node = tmp;
	while (tmp)
	{
		if (v(tmp) > v(node))
			node = tmp;
		tmp = tmp->next;
	}
	return (node);
}
