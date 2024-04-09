/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:38:25 by proton            #+#    #+#             */
/*   Updated: 2024/04/09 14:02:55 by bproton          ###   ########.fr       */
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

char	*open_input_file(const char *str);
char	**ft_split(char const *s, char c);
int		parse_arguments(char *arg1, char *arg2);

#endif