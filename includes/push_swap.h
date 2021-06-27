/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 16:04:48 by llalba            #+#    #+#             */
/*   Updated: 2021/06/27 17:58:04 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/uio.h>
# include <sys/types.h>
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
short	is_new(t_list *tmp, void *content);
void	free_str_ptr(char **ptr);
short	is_int(char *str);

#endif
