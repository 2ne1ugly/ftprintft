CC=clang
CFLAGS=-Werror -Wextra -Wall -g -Iincludes -Ilibft
LFLAGS=-Llibft/ -lft
SRC=$(wildcard src/*)
NAME=libftprintf.a
OBJ=$(SRC:src/%.c=%.o)
SHELL := /bin/bash

.PHONY: clean fclean all re norm norme debug test norman update

VPATH = src obj includes

$(NAME): $(OBJ)
	@make -C libft
	ar rc $(NAME) obj/* libft/obj/*
	ranlib $(NAME)
	@echo "$(NAME) build complete!"

all: $(NAME)

%.o: %.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -o obj/$@ -c $<

clean:
	@make -C libft/ clean
	@rm -rf obj/

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all

norm:
	norminette src/. includes/.

test:
	$(CC) -g main.c src/*c -Iincludes -Ilibft $(LFLAGS) -o test

norme: norm

norman:
	-norminette * | grep -iv warning