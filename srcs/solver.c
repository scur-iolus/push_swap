/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 08:43:01 by llalba            #+#    #+#             */
/*   Updated: 2021/07/23 11:02:59 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

static void	a_to_b(t_stacks *s, int init_len)
{
	int		curr_len;

	curr_len = init_len;
	while (!is_sorted(s) && curr_len > init_len / 2 + init_len % 2)
	{
		if (curr_len == 3)
			sort3_a(s);
		if (ft_lstsize(s->stck_b) == 3)
			sort3_b(s);
		if (in_lower_half(s->stack_a, (int)s->stack_a->content, init_len))
		{
			execute("pb", s);
			move_b_top(s);
		}
		else
			execute("ra", s);
		curr_len = ft_lstsize(s->stack_a);
	}
}

static int	b_to_a(t_stacks *s)
{
	int		init_len;
	int		curr_len;

	init_len = ft_lstsize(s->stack_b);
	curr_len = init_len;
	while (!is_sorted(s) && curr_len > init_len / 2 + init_len % 2)
	{
		if (curr_len == 3)
			sort3_b(s);
		if (ft_lstsize(s->stck_a) == 3)
			sort3_a(s);
		if (in_upper_half(s->stack_b, (int)s->stack_b->content, init_len))
			execute("pa", s); // move_a_top(s);
			
		else
			execute("rb", s);
		curr_len = ft_lstsize(s->stack_b);
	}
	return (curr_len);
}

static void	insertion_sort(t_stacks *s, int deepth)
{
	t_list	*bottom;
	t_list	*stop;

	stop = ft_lstlast(s->stack_a);
	while (deepth)
	{
		bottom = ft_lstlast(s->stack_a);
		if ((int)s->stack_a->content > (int)s->stack_a->next->content)
			execute("sa", s);
		if (bottom == stop || (int)bottom->content < (int)s->stack_a->content)
		{
			execute("ra", s);
			deepth--;
		}
		else
		{
			execute("rra", s);
			deepth++;
		}
	}
/*i
	t_list	*tmp;
	t_list	*min;
	int		i;

	if (!ft_lstsize(s->stack_a))
		return ;
	i = 0;
	tmp = s->stack_a;
	min = tmp;
	while (i < deepth)
	{
		if ((int)min->content > (int)tmp->content)
			min = tmp;
		i++;
		tmp = tmp->next;
	}
	tmp = s->stack_a;
	i = 0;
	while (deepth)
	{
		while ((int)min->content != (int)tmp->content)
		{
			tmp = tmp->next;
			execute("pb", s);
			move_b_top(s);
		}
		execute("ra", s);
		deepth--;
	}
*/
}

void	solve(t_stacks *s)
{
	int		b_len;
	int		part_len;

	ft_lstadd_front(&s->parts, ft_lstnew((void *)ft_lstsize(s->stack_a)));
	while (!is_sorted(s))
	{
		if ((int)s->parts->content < THRESHOLD)
		{
			insertion_sort(s, (int)s->parts->content);
			free(ft_lstpop(&s->parts));
		}
		else
		{
			a_to_b(s, (int)s->parts->content);
			free(ft_lstpop(&s->parts));
			b_len = ft_lstsize(s->stack_b);
			while (!is_sorted(s) && b_len > 0)
			{
				part_len = b_len;
				b_len = b_to_a(s);
				part_len -= b_len;
				ft_lstadd_front(&s->parts, ft_lstnew((void *)part_len));
			}
		}
	}
}
