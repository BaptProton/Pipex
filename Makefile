# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: proton <proton@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 17:38:37 by proton            #+#    #+#              #
#    Updated: 2024/04/17 17:46:21 by proton           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRCS = pipex.c ft_split.c ft_split_path.c \

OBJECT = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECT)
	$(CC) $(OBJECT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(NAME) $(OBJECT)

fclean: clean
	rm -f $(NAME)

re: clean fclean all

.PHONY: all clean fclean re
