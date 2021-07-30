/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 15:27:07 by llalba            #+#    #+#             */
/*   Updated: 2021/07/30 16:12:38 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "../libft/libft.h"
# include <stdlib.h>
# ifndef MAX_STACK_LEN
#  define MAX_STACK_LEN 10000
# endif

typedef struct s_stacks
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*parts;
	long	len;
}				t_stacks;

/*
** main.c
*/

long	ft_stacksize(int argc, char **argv);
short	ft_load(t_list **stack, int argc, char **argv);

/*
** utils.c
*/

void	lstdel(void *element);
void	ft_error(void);
int		free_str_ptr(char ***ptr);
short	is_int(char *str);
void	execute(const char *str, t_stacks *s);

/*
** operations.c
*/

void	rotate(t_list **stack);
void	rev_rotate(t_list **stack);
void	swap(t_list **stack);
void	push(t_list **from, t_list **to);

#endif
