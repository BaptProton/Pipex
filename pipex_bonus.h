/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:38:25 by proton            #+#    #+#             */
/*   Updated: 2024/04/25 14:04:27 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

# define BUFFERSIZE 500

char	**ft_split(char const *s, char c);
char	*find_path(char **envp, char *cmd);
char	*research_path(char *path, char *cmd);
char	**ft_split_path(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		parse_arguments(char *arg, char **envp);
int		make_cmd(char *arg, char **envp);
int		print_errors(char *str);
int		parent_process(int *fd);

#endif