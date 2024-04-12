/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:38:16 by proton            #+#    #+#             */
/*   Updated: 2024/04/12 08:43:06 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parse_arguments(char *input, char *arg, char *output, char **envp)
{
	int		fd;
	int		pid;
	char	**n_arg;

	pipe(fd);
	pid = fork();
	n_arg = ft_split(arg, ' ');
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		fd = open(input, O_RDONLY);
		dup2(fd, STDIN_FILENO);
	}
	else
	{
		wait(pid);
		execve(input, n_arg, envp);
		
	}
	pipe(fd);
	if ()
}

int	main(int argc, char **argv, char **envp)
{
	int	j;

	j = 2;
	if (argc > 4)
	{
		while (argc != argc - 1)
		{
			parse_arguments(argv[1], argv[j], argc, envp);
			j++;
			
		}

	}
}
