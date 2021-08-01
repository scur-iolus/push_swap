/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:08:59 by llalba            #+#    #+#             */
/*   Updated: 2021/07/30 15:41:22 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	update_min(t_list **min, t_list *tmp, int *pos, int i)
{
	if (!(*min) || v(*min) > v(tmp))
	{
		*min = tmp;
		*pos = i;
	}
}

static int	get_min_pos(t_stacks *s, int a_depth)
{
	int		i;
	int		pos;
	t_list	*tmp;
	t_list	*min;

	i = 0;
	if (a_depth)
		tmp = s->stack_a;
	min = 0;
	while (i < a_depth)
	{
		update_min(&min, tmp, &pos, i);
		i++;
		tmp = tmp->next;
	}
	tmp = s->stack_b;
	i = -1;
	while (tmp)
	{
		update_min(&min, tmp, &pos, i);
		i--;
		tmp = tmp->next;
	}
	return (pos);
}

static void	shift_min_B(t_stacks *s, int *b_depth, int *a_depth, int *min_pos)
{
	int	worst_case;

	worst_case = (*b_depth) / 2;
	if (*min_pos == -1 || worst_case + 1 > *a_depth - 1)
	{
		(*b_depth)--;
		(*a_depth)++;
		execute("pa", s);
		(*min_pos)++;
	}
	else if (-worst_case <= *min_pos)
	{
		execute("rb", s);
		(*min_pos)++;
	}
	else
	{
		execute("rrb", s);
		(*min_pos)--;
		if (*min_pos < -(*b_depth))
			*min_pos = -1;
	}
}

static void	shift_min_A(t_stacks *s, int *b_depth, int *a_depth, int *min_pos)
{
	(*a_depth)--;
	(*b_depth)++;
	execute("pb", s);
	(*min_pos)--;
}

void	insertion_sort_AB(t_stacks *s, int depth)
{
	int		a_depth;
	int		b_depth;
	int		min_pos;

	a_depth = depth;
	b_depth = 0;
	while (a_depth + b_depth)
	{
		min_pos = get_min_pos(s, a_depth);
		while (min_pos)
		{
			if (min_pos < 0)
				shift_min_B(s, &b_depth, &a_depth, &min_pos);
			else
				shift_min_A(s, &b_depth, &a_depth, &min_pos);
		}
		a_depth--;
		if (s->stack_a->next)
			execute("ra", s);
	}
}
