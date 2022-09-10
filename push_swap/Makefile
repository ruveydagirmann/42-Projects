# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ragirman <ragirman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/02 04:31:55 by ragirman          #+#    #+#              #
#    Updated: 2022/07/02 04:31:58 by ragirman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_FILES = main.c list2.c list.c indexing.c ft_atoi.c error.c count.c \
args_list.c args_check.c alignment.c alignment_together.c

OBJ_SRC = $(SRC_FILES:.c=.o)

CC = @gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ_SRC)
		@make all -C ./Libft
		$(CC) $(CFLAGS) $(OBJ_SRC) Libft/libft.a -o $(NAME)
		
clean:
	rm -rf $(OBJ_SRC)
	make -C ./Libft fclean

fclean: clean
	rm -rf $(OBJ_SRC) $(NAME)
	make -C ./Libft fclean

re: fclean all

.PHONY: all re clean fclean