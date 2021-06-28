/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:04:48 by llalba            #+#    #+#             */
/*   Updated: 2021/06/28 18:27:27 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/uio.h>
# include <sys/types.h>
#include <stdio.h> // ==================================================================

/*
** libft modifs: atoi, ft_lst*, ft_lstsecondtolast, header
*/

# include "../libft/libft.h"

typedef struct	s_stacks
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		len;
}				t_stacks;

/*
** utils.c
*/

void	lstdel(void *element);
void	ft_error();
void	free_str_ptr(char **ptr);
short	is_int(char *str);
void	execute(const char *str, t_stacks *s);

/*
** operations.c
*/

void	rotate(t_list **stack);
void	rev_rotate(t_list **stack);
void	swap(t_list **stack);
void	push(t_list **from, t_list **to);

/*
** fast_sort.c
*/

short	sort2(t_stacks *s, char c);
short	sort3_a(t_stacks *s);
short	sort3_b(t_stacks *s);
short	is_sorted(t_stacks *s);

/*
** solver.c
*/

void	quicksort(t_stacks *s);
void	print_stack(t_list *tmp, const char *str); // ================================

#endif
