# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llalba <llalba@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/24 16:05:23 by llalba            #+#    #+#              #
#    Updated: 2021/07/30 16:26:06 by llalba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= checker

CC			= gcc

FLAGS		= -Wall -Werror -Wextra

LIBFT_PATH	= libft/

LIBFT_OBJS	= $(LIBFT_PATH)*.o

SRCS_PATH	= srcs/

PS_PATH		= ../01_solver/srcs/

H_FOLDER	= includes/

SRCS_FILES	= \
			$(SRCS_PATH)get_next_line.c \
			$(SRCS_PATH)checker.c \
			$(PS_PATH)operations.c \
			$(PS_PATH)parser.c \
			$(PS_PATH)utils.c


SRCS_OBJS	= $(SRCS_FILES:.c=.o)

$(NAME):	$(SRCS_OBJS)
			@make bonus -C libft
			@echo "Binary files up to date or updated."
			$(CC) $(FLAGS) -o $(NAME) $(SRCS_OBJS) \
			-L$(PWD)/$(LIBFT_PATH) -lft

all:		$(NAME)

clean:
			make clean -C libft
			rm -rf $(SRCS_OBJS)

fclean:		clean
			make fclean -C libft
			rm -f $(NAME)

re:			fclean all

norme:
			norminette ./$(LIBFT_PATH)*.c
			@echo
			norminette ./$(H_FOLDER)*.h
			@echo
			norminette $(SRCS_FILES)

.PHONY:		all clean fclean re
