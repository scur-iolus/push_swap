/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llalba <llalba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:57:38 by llalba            #+#    #+#             */
/*   Updated: 2021/08/01 14:12:29 by llalba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

long long	ft_atoi(const char *str);
void		ft_putchar_fd(char c, int fd);
char		**ft_split(char const *str, char c);
size_t		ft_strlen(const char *s);
int			ft_strcmp(const char *s1, const char *s2);
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lstadd_front(t_list **alst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstsecondtolast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
t_list		*ft_lstpop(t_list **lst);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstintmax(t_list *a);
t_list		*ft_lstintmin(t_list *a);
int			v(t_list *l);
#endif
