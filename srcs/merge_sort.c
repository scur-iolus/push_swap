/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 19:18:03 by llalba            #+#    #+#             */
/*   Updated: 2021/07/27 17:17:54 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

static void	move_b_top(t_stacks *s)
{
	int	b_len;

	b_len = ft_lstsize(s->stack_b);
	if (b_len >= 3)
		if ((int)s->stack_b->content < (int)ft_lstlast(s->stack_b)->content)
			execute("rb", s);
	if (b_len >= 2)
		if ((int)s->stack_b->content < (int)s->stack_b->next->content)
			execute("sb", s);
}

static void	rewind_a(int i, t_stacks *s)
{
	while (i)
	{
		execute("rra", s);
		i--;
	}
}

static int	a_to_b(t_stacks *s, int depth)
{
	int				part_len;
	int				bottom_len;
	int				i;
	static short	first_time = 1;

	free(ft_lstpop(&s->parts));
	i = 0;
	part_len = depth;
	bottom_len = 0;
	while (i < depth)
	{
		if (in_lower_half(s, part_len - bottom_len, bottom_len, depth))
		{
			execute("pb", s);
			part_len--;
			move_b_top(s);
		}
		else
		{
			execute("ra", s);
			bottom_len++;
		}
		i++;
	}
	if (!first_time)
		rewind_a(bottom_len, s);
	first_time = 0;
	return (part_len);
}

static int	b_to_a(t_stacks *s)
{
	int	init_len;
	int	curr_len;
	int	i;

	init_len = ft_lstsize(s->stack_b);
	if (!init_len)
		return (0);
	curr_len = init_len;
	i = 0;
	while (i < init_len)
	{
		if (in_upper_half(s->stack_b, init_len))
		{
			execute("pa", s);
			curr_len--;
		}
		else
			execute("rb", s);
		i++;
	}
	return (init_len - curr_len);
}

void	merge_sort(t_stacks *s)
{
	int		part_len;

	part_len = a_to_b(s, (int)s->parts->content);
	ft_lstadd_front(&s->parts, ft_lstnew((void *)(size_t)part_len));
	while (part_len > 0)
	{
		part_len = b_to_a(s);
		if (part_len > 0)
			ft_lstadd_front(&s->parts, ft_lstnew((void *)(size_t)part_len));
	}
}
