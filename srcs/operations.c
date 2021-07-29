/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 08:49:36 by llalba            #+#    #+#             */
/*   Updated: 2021/07/29 18:51:30 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	swap(t_list **stack)
{
	t_list	*tmp;

	if (*stack == 0 || (*stack)->next == 0)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

void	push(t_list **from, t_list **to)
{
	t_list	*tmp;

	if (*from == 0)
		return ;
	tmp = (*from)->next;
	ft_lstadd_front(to, *from);
	*from = tmp;
}

void	rotate(t_list **stack)
{
	t_list	*tmp;

	if (*stack == 0 || (*stack)->next == 0)
		return ;
	tmp = *stack;
	ft_lstlast(*stack)->next = tmp;
	*stack = tmp->next;
	tmp->next = 0;
}

void	rev_rotate(t_list **stack)
{
	t_list	*tmp;

	if (*stack == 0 || (*stack)->next == 0)
		return ;
	tmp = *stack;
	*stack = ft_lstlast(*stack);
	ft_lstsecondtolast(tmp)->next = 0;
	(*stack)->next = tmp;
}
