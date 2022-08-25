# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/25 12:40:22 by marvin            #+#    #+#              #
#    Updated: 2022/08/25 12:40:24 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= so_long
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
SRCS		= $(wildcard srcs/*.c) $(wildcard utils/*.c)
OBJS		= $(SRCS:%.c=%.o)
$(NAME):	$(OBJS)
			make -C ./mlx
			mv ./mlx/libmlx.a ./libmlx.a
			$(CC) $(CFLAGS) $(SRCS) -framework OpenGL -framework AppKit libmlx.a -o $(NAME)

all: 		$(NAME)

clean:
			make -C ./mlx clean
			rm -rf */*.o libmlx.a so_long.o

fclean: 	clean
			rm -rf so_long

re: 		fclean all

.PHONY: 	all clean fclean re