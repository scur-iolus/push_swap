/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 12:08:53 by llalba            #+#    #+#             */
/*   Updated: 2021/08/01 14:18:48 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	vs_B(t_stacks *s, int *i, int n)
{
	t_list	*tmp;

	tmp = s->stack_b;
	while (tmp)
	{
		if (n < v(tmp))
			(*i)++;
		tmp = tmp->next;
	}
}

static void	vs_A_top(int top_len, int *i, int n, t_list **tmp)
{
	while (top_len)
	{
		if (n < v(*tmp))
			(*i)++;
		*tmp = (*tmp)->next;
		top_len--;
	}
}

static void	vs_A_bottom(int bottom_len, int *i, int n, t_list *tmp)
{
	while (bottom_len)
	{
		if (n < v(tmp))
			(*i)++;
		tmp = tmp->next;
		bottom_len--;
	}
}

short	in_lower_half(t_stacks *s, int top_len, int bottom_len, int len)
{
	int			i;
	int			a_len;
	int			n;
	t_list		*tmp;

	i = 0;
	n = v(s->stack_a);
	vs_B(s, &i, n);
	if ((10 * (long)i) >= 10 * (long)len / 2)
		return (1);
	tmp = s->stack_a;
	vs_A_top(top_len, &i, n, &tmp);
	if ((10 * (long)i) >= 10 * (long)len / 2)
		return (1);
	a_len = ft_lstsize(s->stack_a);
	while (a_len - top_len - bottom_len > 0)
	{
		tmp = tmp->next;
		a_len--;
	}
	vs_A_bottom(bottom_len, &i, n, tmp);
	if ((10 * (long)i) >= 10 * (long)len / 2)
		return (1);
	return (0);
}

short	in_upper_half(t_list *head, int len)
{
	int			i;
	int			n;

	i = 0;
	n = v(head);
	while (head)
	{
		if (n >= v(head))
			i++;
		if ((10 * (long)i) > 10 * (long)len / 2)
			return (1);
		head = head->next;
	}
	return (0);
}
