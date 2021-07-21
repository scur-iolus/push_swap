/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 08:43:01 by llalba            #+#    #+#             */
/*   Updated: 2021/07/21 17:17:06 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

static short	in_lower_half(t_list *head, int n, int len)
{
	int			i;

	i = 0;
	while (head)
	{
		if (n < (int)head->content)
			i++;
		if ((10 * (long)i) >= 10 * (long)len / 2)
			return (1);
		head = head->next;
	}
	return (0);
}

static short	in_upper_half(t_list *head, int n, int len)
{
	int			i;

	i = 0;
	while (head)
	{
		if (n > (int)head->content || len == 1)
			i++;
		if ((10 * (long)i) >= 10 * (long)len / 2)
			return (1);
		head = head->next;
	}
	return (0);
}

void	move_b_top(t_stacks *s)
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

void	move_a_top(t_stacks *s)
{
	int	a_len;

	a_len = ft_lstsize(s->stack_a);
	if (a_len >= 3)
		if ((int)s->stack_a->content > (int)ft_lstlast(s->stack_a)->content)
			execute("ra", s);
	if (a_len >= 2)
		if ((int)s->stack_a->content > (int)s->stack_a->next->content)
			execute("sa", s);
}

int	a_to_b(t_stacks *s)
{
	int		init_len;
	int		curr_len;

	init_len = ft_lstsize(s->stack_a);
	curr_len = init_len;
	while (!is_sorted(s) && curr_len > init_len / 2 + init_len % 2)
	{
		if (curr_len == 3)
			sort3_a(s);
		if (ft_lstsize(s->stck_b) == 3)
			sort3_b(s);
		if (in_lower_half(s->stack_a, (int)s->stack_a->content))
		{
			execute("pb", s);
			move_b_top(s);
		}
		else
			execute("ra", s);
		curr_len = ft_lstsize(s->stack_a);
	}
	return (curr_len);
}

int	b_to_a(t_stacks *s)
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
		if (in_upper_half(s->stack_b, (int)s->stack_b->content))
		{
			execute("pa", s);
			move_a_top(s);
		}
		else
			execute("rb", s);
		curr_len = ft_lstsize(s->stack_b);
	}
	return (curr_len);
}

void	insertion_sort(t_stacks *s, int deepth)
{
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
			execute("pb", s);
			move_b_top(s);
			tmp = tmp->next;
		}
		execute("ra", s);
		deepth--;
	}
}

void	quicksort(t_stacks *s)
{
	if (!is_sorted(s))
		(void)a_to_b(s);
	while (!is_sorted(s) && b_to_a(s) > 0)
		;
	insertion_sort(s, );
}

/*
void	solve(t_stacks *s)
{
	long	i;


}
*/

