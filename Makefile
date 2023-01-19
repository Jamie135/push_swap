# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pbureera <pbureera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/04 12:02:23 by pbureera          #+#    #+#              #
#    Updated: 2023/01/19 12:27:39 by pbureera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS =	srcs/push_swap.c \
		srcs/instructions.c \
		srcs/sort.c \
		srcs/sort_utils.c \
		srcs/sort_big_utils.c \
		srcs/utils.c

OBJS = $(SRCS:.c=.o)

SRCS_BONUS =	srcs/push_swap_utils.c \
				srcs/instructions.c \
				srcs/get_next_line.c \
				srcs/checker.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME) :	$(OBJS)
	make re -C ./libft
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft -o $(NAME)

bonus :	$(OBJS_BONUS)
	make re -C ./libft
	$(CC) $(CFLAGS) $(OBJS_BONUS) -Llibft -lft -o $(NAME)

clean:
	make clean -C ./libft
	$(RM) $(NAME)
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	make fclean -C ./libft
	$(RM) $(NAME)

re: fclean all