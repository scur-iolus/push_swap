/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 08:43:01 by llalba            #+#    #+#             */
/*   Updated: 2021/07/26 14:55:44 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

static short	is_sorted(t_stacks *s)
{
	t_list	*tmp;
	int		a_head;

	tmp = s->stack_a;
	a_head = (int)tmp->content;
	while (tmp->next)
	{
		if ((int)tmp->content >= (int)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	tmp = s->stack_b;
	if (!tmp)
		return (1);
	if ((int)tmp->content >= a_head)
		return (0);
	while (tmp->next)
	{
		if ((int)tmp->content <= (int)tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	while (s->stack_b)
		execute("pa", s);
	return (1);
}

void	solve(t_stacks *s)
{
	int		a_len;

	a_len = ft_lstsize(s->stack_a);
	ft_lstadd_front(&s->parts, ft_lstnew((void *)(size_t)a_len));
	while (!is_sorted(s))
	{
		if ((int)s->parts->content < THRESHOLD)
		{
			insertion_sort_AB(s, (int)s->parts->content);
			free(ft_lstpop(&s->parts));
		}
		else
			merge_sort(s);
	}
}
