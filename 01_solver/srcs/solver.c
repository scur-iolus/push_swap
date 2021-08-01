/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 08:43:01 by llalba            #+#    #+#             */
/*   Updated: 2021/08/01 14:18:23 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	final_rotation(t_stacks *s)
{
	t_list	*a_min;
	t_list	*tmp;
	int		min_pos;
	int		worst_case;

	min_pos = 0;
	tmp = s->stack_a;
	a_min = ft_lstintmin(s->stack_a);
	while (tmp != a_min)
	{
		tmp = tmp->next;
		min_pos++;
	}
	worst_case = ft_lstsize(s->stack_a) / 2;
	while (s->stack_a != a_min)
	{
		if (min_pos <= worst_case)
			execute("ra", s);
		else
			execute("rra", s);
	}
}

static void	rotate_a(t_stacks *s, int i)
{
	t_list	*tmp;
	int		j;

	j = i;
	tmp = s->stack_a;
	while (j)
	{
		tmp = tmp->next;
		j--;
	}
	while (tmp && i)
	{
		execute("ra", s);
		i--;
	}
}

short	is_sorted(t_stacks *s)
{
	t_list	*tmp;
	int		a_head;

	tmp = s->stack_a;
	a_head = v(tmp);
	while (tmp->next)
	{
		if (v(tmp) >= v(tmp->next))
			return (0);
		tmp = tmp->next;
	}
	tmp = s->stack_b;
	if (!tmp)
		return (1);
	if (v(tmp) >= a_head)
		return (0);
	while (tmp->next)
	{
		if (v(tmp) <= v(tmp->next))
			return (0);
		tmp = tmp->next;
	}
	while (s->stack_b)
		execute("pa", s);
	return (1);
}

void	solve(t_stacks *s)
{
	int		len;

	len = ft_lstsize(s->stack_a);
	ft_lstadd_front(&s->parts, ft_lstnew((void *)(size_t)len));
	while (!is_sorted(s))
	{
		len = v(s->parts);
		if (len < THRESHOLD)
		{
			if (sort3(s, s->stack_a) || sort5(s))
				return ;
			else if (sort3_a(s->stack_a, len, s))
				rotate_a(s, 3);
			else if (sort4_a(len, s))
				;
			else if (sort5_a(len, s))
				;
			else
				insertion_sort_AB(s, len);
			free(ft_lstpop(&s->parts));
		}
		else
			merge_sort(s);
	}
}
