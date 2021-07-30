/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:04:48 by llalba            #+#    #+#             */
/*   Updated: 2021/07/30 15:50:28 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "common.h"
# include <unistd.h>
# include <sys/uio.h>
# include <sys/types.h>
# ifndef THRESHOLD
#  define THRESHOLD 33
# endif

/*
** sort3.c, sort4.c, sort5.c
*/

short	sort3(t_stacks *s, t_list *a);
short	sort3_a(t_list *a, int a_len, t_stacks *s);
short	sort3_b(t_list *b, int b_len, t_stacks *s);
short	sort4_a(int a_len, t_stacks *s);
short	sort5(t_stacks *s);
short	sort5_a(int a_len, t_stacks *s);

/*
** insertion_sort.c
*/

void	insertion_sort_AB(t_stacks *s, int depth);

/*
** solver.c
*/

void	final_rotation(t_stacks *s);
int		v(t_list *l);
short	is_sorted(t_stacks *s);
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
