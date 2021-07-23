# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llalba <llalba@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/28 10:13:05 by llalba            #+#    #+#              #
#    Updated: 2021/07/23 11:21:03 by llalba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libft.a

SRCS =		ft_atoi.c \
			ft_split.c \
			ft_strlen.c \
			ft_putchar_fd.c

OBJ =		${SRCS:.c=.o}

FLAGS =		-Wall -Werror -Wextra

CC			= gcc

.c.o:		${CC} ${FLAGS} -g -c $< -o ${<:.c=.o}

BONUS =		ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstsecondtolast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstpop.c

$(NAME):	${OBJ}
			@ar rcs $@ $^
			@echo "libft.a generated."

BONUS_OBJ =	${BONUS:.c=.o}

bonus:		${OBJ} ${BONUS_OBJ}
			@ar rcs ${NAME} $^
			@echo "libft.a generated with bonus functions."

all:		${NAME}

clean:
			rm -f ${OBJ} $(BONUS_OBJ)

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus
