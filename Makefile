# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bproton <bproton@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 17:38:37 by proton            #+#    #+#              #
#    Updated: 2024/04/12 15:17:46 by bproton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = pipex.c ft_split.c \

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
