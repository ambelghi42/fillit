# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ambelghi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/05 13:19:46 by ambelghi          #+#    #+#              #
#    Updated: 2019/08/21 19:56:47 by ambelghi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = main.c	   \
	   functions.c \
	   solve.c \
	   utils.c \
	   utils_2.c \
	   check.c
OBJS = $(SRCS:.c=.o)
GCC = gcc
INCLUDES = -I ./libft
FLAGS += -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft
	$(GCC) $(FLAGS) $(INCLUDES) -c $(SRCS)
	$(GCC) $(FLAGS) $(INCLUDES) $(OBJS) -L libft/ -lft  -o $(NAME)
clean:
	make -C libft clean
	rm -rf $(OBJS)

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)

re: fclean all
