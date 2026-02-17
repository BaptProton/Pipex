# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: proton <proton@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 17:38:37 by proton            #+#    #+#              #
#    Updated: 2026/02/17 11:57:36 by proton           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
NAME_BONUS = pipex_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iinclude
OBJDIR = obj

SRCS =	src/pipex.c src/ft_split.c src/ft_split_path.c src/pipex_utils.c src/pipex_utils2.c

SRCS_B =	src/pipex_bonus.c src/ft_split_bonus.c src/ft_split_path_bonus.c \
			src/pipex_utils_bonus.c src/pipex_utils2_bonus.c

OBJECT = $(patsubst src/%.c,$(OBJDIR)/%.o,$(SRCS))
OBJ_B = $(patsubst src/%.c,$(OBJDIR)/%.o,$(SRCS_B))

all: $(NAME)

$(NAME): $(OBJECT)
	$(CC) $(OBJECT) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_B)
	$(CC) $(OBJ_B) -o $(NAME_BONUS)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: clean fclean all

rebonus: fclean bonus

.PHONY: all bonus clean fclean re rebonus
