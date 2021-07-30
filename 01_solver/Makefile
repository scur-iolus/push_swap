# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llalba <llalba@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/24 16:05:23 by llalba            #+#    #+#              #
#    Updated: 2021/07/30 16:47:58 by llalba           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

CC			= gcc

FLAGS		= -Wall -Werror -Wextra

LIBFT_PATH	= libft/

LIBFT_OBJS	= $(LIBFT_PATH)*.o

SRCS_PATH	= srcs/

H_FOLDER	= includes/

SRCS_FILES	= \
			$(SRCS_PATH)main.c \
			$(SRCS_PATH)operations.c \
			$(SRCS_PATH)sort3.c \
			$(SRCS_PATH)sort4.c \
			$(SRCS_PATH)sort5.c \
			$(SRCS_PATH)merge_sort.c \
			$(SRCS_PATH)insertion_sort.c \
			$(SRCS_PATH)solver.c \
			$(SRCS_PATH)list_split.c \
			$(SRCS_PATH)parser.c \
			$(SRCS_PATH)utils.c

SRCS_OBJS	= $(SRCS_FILES:.c=.o)

$(NAME):	$(SRCS_OBJS)
			@make bonus -C libft
			@echo "Binary files up to date or updated."
			$(CC) $(FLAGS) -fsanitize=address -o $(NAME) $(SRCS_OBJS) \
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

test:		$(NAME)
			./push_swap ${ARG} | wc -l
			./push_swap ${ARG} | ./checker_Mac ${ARG}

.PHONY:		all clean fclean re
