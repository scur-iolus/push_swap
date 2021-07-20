/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 08:43:01 by llalba            #+#    #+#             */
/*   Updated: 2021/07/20 17:33:38 by llalba           ###   ########.fr       */
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

static short	in_upper_half(t_list *head, int n)
{
	int			i;
	static int	init_len = -1;
	int			curr_len;

	i = 0;
	if (init_len == -1)
		init_len = ft_lstsize(head);
	curr_len = ft_lstsize(head);
	if (curr_len <= init_len / 2 + init_len % 2)
	{ // ===================================================
		init_len = curr_len;
		// printf("new med\n"); // ===================================================
	} // ===================================================
	while (head)
	{
		if (n > (int)head->content)
			i++;
		if ((10 * (long)i) >= 10 * (long)init_len / 2)
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

void	a_to_b(t_stacks *s)
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
	}
}

void	b_to_a(char c, t_stacks *s)
{
	int		init_len;
	int		curr_len;

	init_len = ft_lstsize(s->stack_b);
	curr_len = init_len;
	while (!is_sorted(s) && curr_len > init_len / 2 + init_len % 2)
	{
		if (curr_len == 3)
		{
			sort3_b(s);
			break ;
		}
		if (ft_lstsize(s->stck_b) == 3)
		{
			sort3_b(s);
			continue ;
		}
		if (in_lower_half(s->stack_a, (int)s->stack_a->content))
		{
			execute("pb", s);
			move_b_top(s);
		}
		else
			execute("ra", s);
	}

https://www.youtube.com/watch?v=egU3YD8OKbw

}



void	quicksort(t_stacks *s)
{
	short	test;

	test = 0;
	while (!is_sorted(s) && test < 200)
	{
		a_to_b('l', s);
		b_to_a('u', s);
		test++;
	}
}

/*
void	solve(t_stacks *s)
{
	long	i;


}
*/

