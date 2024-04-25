# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bproton <bproton@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 17:38:37 by proton            #+#    #+#              #
#    Updated: 2024/04/25 16:26:01 by bproton          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRCS =	pipex.c ft_split.c ft_split_path.c pipex_utils.c pipex_utils2.c \

BONUSRCS =	pipex_bonus.c ft_split_bonus.c ft_split_path_bonus.c \
			pipex_utils_bonus.c pipex_utils2_bonus.c \

OBJECT = $(SRCS:.c=.o)
BONOBJ = $(BONUSRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECT)
	$(CC) $(OBJECT) -o $(NAME)

bonus: $(NAME_BONUS) $(BONOBJ)
	$(CC) $(BONOBJ) -o $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(NAME) $(OBJECT) $(BONOBJ)

fclean: clean
	rm -f $(NAME)

re: clean fclean all

re bonus: fclean bonus

.PHONY: all clean fclean re
