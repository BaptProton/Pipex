# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: proton <proton@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 17:38:37 by proton            #+#    #+#              #
#    Updated: 2024/04/26 09:29:15 by proton           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS =	pipex.c ft_split.c ft_split_path.c pipex_utils.c pipex_utils2.c \

SRCS_B =	pipex_bonus.c ft_split_bonus.c ft_split_path_bonus.c \
			pipex_utils_bonus.c pipex_utils2_bonus.c \

OBJECT = $(SRCS:.c=.o)
OBJ_B = $(SRCS_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJECT)
	$(CC) $(OBJECT) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_B)
	$(CC) $(OBJ_B) -o $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(NAME) $(OBJECT) $(OBJ_B)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: clean fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re
