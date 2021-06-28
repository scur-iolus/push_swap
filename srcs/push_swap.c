/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 08:49:36 by llalba            #+#    #+#             */
/*   Updated: 2021/06/28 09:56:14 by llalba           ###   ########.fr       */
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

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
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
