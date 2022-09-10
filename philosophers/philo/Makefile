NAME = philo

SRC = control.c get_time.c init.c judge_verb.c verb.c main.c utils.c

CC = gcc

CFLAGS = -Wall -Wextra -Werror  #-fsanitize=thread -g

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ) philo.h
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
		rm -rf $(OBJ)

fclean:
		rm -rf $(OBJ) $(NAME)

re: fclean all

.PHONY: all re clean fclean
