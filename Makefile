# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffeaugas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/13 13:11:13 by ffeaugas          #+#    #+#              #
#    Updated: 2022/12/13 14:27:00 by ffeaugas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS = --no-print-directory
NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT = libft/
SRCS =	error.c \
		parse.c \
		pipex.c \
		utils.c

OBJ = $(SRCS:%.c=srcs/%.o)

all: $(NAME)

$(NAME): $(OBJ)
		@echo "\n[Compilation in progress...]"
		@make -sC $(LIBFT)
		@echo "[...]"
		@$(CC) $(OBJ) libft/libft.a -o $(NAME)
		@echo "[Compilation successfully completed !]\n"

srcs/%.o: srcs/%.c
		@$(CC) $(CFLAGS) -I includes -I libft -c $< -o $@

clean:
		@make -sC $(LIBFT) clean
		@rm -f $(OBJ)

fclean: clean
		@make -sC $(LIBFT) fclean
		@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
