/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fast_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 11:12:44 by llalba            #+#    #+#             */
/*   Updated: 2021/06/28 18:31:01 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

short	sort2(t_stacks *s, char c)
{
	if (c == 'a')
	{
		if (!s->stack_a || !s->stack_a->next)
			return (0);
		if (s->stack_a < s->stack_a->next)
			;
		else
			execute("sa", s);
	}
	else
	{
		if (!s->stack_b || !s->stack_b->next)
			return (0);
		if (s->stack_b < s->stack_b->next)
			;
		else
			execute("sb", s);
	}
	return (1);
}

static int	v(t_list *l)
{
	return ((int)(l->content));
}

short	sort3_a(t_stacks *s)
{
	t_list	*a;

	a = s->stack_a;
	if (v(a) < v(a->next->next) && v(a->next->next) < v(a->next))
		execute("sa", s);
	a = s->stack_a;
	if (v(a->next->next) < v(a->next) && v(a->next) < v(a))
		execute("sa", s);
	a = s->stack_a;
	if (v(a->next) < v(a->next->next) && v(a->next->next) < v(a))
		execute("ra", s);
	a = s->stack_a;
	if (v(a->next->next) < v(a) && v(a) < v(a->next))
		execute("rra", s);
	a = s->stack_a;
	if (v(a->next) < v(a) && v(a) < v(a->next->next))
		execute("sa", s);
	return (1);
}

short	sort3_b(t_stacks *s) // ordre doit etre decroissant ici
{
	t_list	*b;

	b = s->stack_b;
	if (v(b) < v(b->next->next) && v(b->next->next) < v(b->next))
		execute("sb", s);
	b = s->stack_b;
	if (v(b->next->next) < v(b->next) && v(b->next) < v(b))
		execute("sb", s);
	b = s->stack_b;
	if (v(b->next) < v(b->next->next) && v(b->next->next) < v(b))
		execute("rb", s);
	b = s->stack_b;
	if (v(b->next->next) < v(b) && v(b) < v(b->next))
		execute("rrb", s);
	b = s->stack_b;
	if (v(b->next) < v(b) && v(b) < v(b->next->next))
		execute("sb", s);
	return (1);
}

short	is_sorted(t_stacks *s)
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
