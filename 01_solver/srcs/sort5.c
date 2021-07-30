/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 09:20:28 by llalba            #+#    #+#             */
/*   Updated: 2021/07/30 15:42:07 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

short	right_place(t_list *a, t_list *b)
{
	t_list	*a_max;
	t_list	*a_min;
	t_list	*tmp;
	int		i;

	a_min = ft_lstintmin(a);
	a_max = ft_lstintmax(a);
	if ((v(b) < v(a) && v(b) > v(ft_lstlast(a))) || \
		(v(b) < v(a_min) && a_min == a) || \
			(v(b) > v(a_max) && a_max == ft_lstlast(a)))
		return (0);
	i = 1;
	tmp = a;
	while (tmp)
	{
		if ((v(b) < v(a_min) || (v(b) > v(a_max))) && v(tmp) > v(tmp->next))
			break ;
		else if (v(b) > v(tmp) && v(b) < v(tmp->next))
			break ;
		tmp = tmp->next;
		i++;
	}
	if (i > ft_lstsize(a) / 2)
		return (-1);
	return (1);
}

short	sort5(t_stacks *s)
{
	int	diff;
	int	i;

	i = 2;
	if (s->len != 5 || s->stack_b)
		return (0);
	execute("pb", s);
	execute("pb", s);
	sort3(s, s->stack_a);
	while (i)
	{
		diff = right_place(s->stack_a, s->stack_b);
		if (!diff)
		{
			execute("pa", s);
			i--;
		}
		else if (diff == 1)
			execute("ra", s);
		else
			execute("rra", s);
	}
	while (!is_sorted(s))
		final_rotation(s);
	return (1);
}

short	sort5_a(int a_len, t_stacks *s)
{
	int	i;

	i = 5;
	if (a_len != i)
		return (0);
	execute("pb", s);
	execute("pb", s);
	sort3_a(s->stack_a, 3, s);
	if (v(s->stack_b) > v(s->stack_b->next))
		execute("sb", s);
	while (i)
	{
		if (s->stack_b && ((v(s->stack_a) > v(s->stack_b)) || i == 1))
			execute("pa", s);
		execute("ra", s);
		i--;
	}
	return (1);
}
