/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:38:25 by proton            #+#    #+#             */
/*   Updated: 2024/04/17 14:48:14 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
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
int		parse_arguments(char *input, char *arg, char *output, char **envp);
char	*find_path(char **envp, char *cmd);
char	*research_path(char *path, char *cmd);
char	**ft_split_path(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);

#endif