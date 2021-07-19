/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 08:43:01 by llalba            #+#    #+#             */
/*   Updated: 2021/07/19 12:14:56 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

static short	in_lower_half(t_list *head, int n)
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
		printf("new med\n"); // ===================================================
	} // ===================================================
	while (head)
	{
		if (n < (int)head->content)
			i++;
		if ((10 * (long)i) >= 10 * (long)init_len / 2)
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
		printf("new med\n"); // ===================================================
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

void	a_to_b(char c, t_stacks *s)
{
	printf("========== Entree boucle\n"); // ====================================
	while (s->stack_a->next)
	{
		if (ft_lstsize(s->stack_a) == 3)
			sort3_a(s);
		if (c == 'l' && in_lower_half(s->stack_a, (int)s->stack_a->content))
		{
			execute("pb", s);
			move_b_top(s);
		}
		else if (c == 'u' && in_upper_half(s->stack_a, (int)s->stack_a->content))
			execute("pb", s);
		else
			execute("ra", s);
		print_stack(s->stack_a, "stack A"); // ====================================
		print_stack(s->stack_b, "stack B"); // =====================================
	}
	printf("========== Fin boucle\n"); // ====================================
}

void	b_to_a(char c, t_stacks *s)
{
	printf("========== Entree boucle\n"); // ====================================
	while (s->stack_b->next)
	{
		if (ft_lstsize(s->stack_a) == 3)
			sort3_a(s);
		if (c == 'l' && in_lower_half(s->stack_b, (int)s->stack_b->content))
			execute("pa", s);
		else if (c == 'u' && in_upper_half(s->stack_b, (int)s->stack_b->content))
		{
			execute("pa", s);
			move_a_top(s);
		}
		else
			execute("rb", s);
		print_stack(s->stack_a, "stack A"); // ====================================
		print_stack(s->stack_b, "stack B"); // =====================================
	}
	printf("========== Fin boucle\n"); // ====================================
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
