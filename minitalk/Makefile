# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/25 12:37:38 by marvin            #+#    #+#              #
#    Updated: 2022/08/25 12:37:39 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



CC = gcc
CFLAGS = -Wall -Werror -Wextra -I./
CLIENT = $(CC) $(CFLAGS) client.c minitalk_utils.c -o client
SERVER = $(CC) $(CFLAGS) server.c minitalk_utils.c -o server
all:
	$(CLIENT)
	$(SERVER)
clean:
	rm -rf client server
fclean: clean
re : all
.PHONY: all clean fclean re