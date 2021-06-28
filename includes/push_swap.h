/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:04:48 by llalba            #+#    #+#             */
/*   Updated: 2021/06/28 09:27:33 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/uio.h>
# include <sys/types.h>

/*
** libft modifs: atoi, ft_lst*, ft_lstsecondtolast
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

/*
** rotate.c
*/

void	rotate(t_list **stack);
void	double_rotate(t_list **stack_a, t_list **stack_b);
void	rev_rotate(t_list **stack);
void	dble_rev_rotate(t_list **stack_a, t_list **stack_b);

#endif
