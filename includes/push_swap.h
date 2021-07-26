/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:04:48 by llalba            #+#    #+#             */
/*   Updated: 2021/07/26 18:49:12 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/uio.h>
# include <sys/types.h>
#include <stdio.h> // ==================================================================
# ifndef THRESHOLD
#  define THRESHOLD 23
# endif

/*
** libft modifs: atoi, ft_lst*, ft_lstsecondtolast, header
*/

# include "../libft/libft.h"

typedef struct	s_stacks
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*parts;
}				t_stacks;

void	print_stack(t_list *tmp, const char *str); // ================================

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

short	sort3_a(t_stacks *s);

/*
** insertion_sort.c
*/

void	insertion_sort_A(t_stacks *s, int depth);
void	insertion_sort_AB(t_stacks *s, int depth);

/*
** solver.c
*/

void	solve(t_stacks *s);

/*
** list_split.c
*/

short	in_upper_half(t_list *head, int len);
short	in_lower_half(t_stacks *s, int top_len, int bottom_len, int len);

/*
** merge_sort.c
*/

void	merge_sort(t_stacks *s);

#endif
