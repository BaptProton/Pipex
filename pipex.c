/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:38:16 by proton            #+#    #+#             */
/*   Updated: 2024/04/19 15:28:50 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **envp, char *cmd)
{
	int		j;
	int		i;
	char	*path;

	path = "PATH=";
	j = -1;
	while (envp[++j])
	{
		i = 0;
		if (envp[j][i] == 'P')
		{
			while (envp[j][i] == path[i])
				i++;
			i--;
			if (envp[j][i] == '=')
				return (research_path(envp[j], cmd));
		}
	}
	return (NULL);
}

int	make_cmd(char *arg, char **envp)
{
	char	*path;
	char	**n_arg;

	n_arg = ft_split(arg, ' ');
	path = find_path(envp, n_arg[0]);
	if (!path)
		exit(127);
	if (execve(path, n_arg, envp) == -1)
		exit(127);
	return (0);
}

int	parse_arguments(char *arg, char **envp)
{
	int	fd[2];
	int	pid;
	int	status;

	if (pipe(fd) == -1)
		return (1);
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		make_cmd(arg, envp);
		exit(EXIT_SUCCESS);
	}
	else
	{
		waitpid(pid, &status, 0);
		close(fd[1]);
		parent_process(fd);
		return (status);
	}
}

int	exec_last_cmd(int out, char *arg, char **envp)
{
	char	**cmd;
	char	*path;

	dup2(out, STDOUT_FILENO);
	cmd = ft_split(arg, ' ');
	path = find_path(envp, cmd[0]);
	if (!path)
		return (0);
	if (execve(path, cmd, envp) == -1)
		exit(127);
	close(out);
	exit(120);
}

int	main(int argc, char **argv, char **envp)
{
	int	j;
	int	infile;
	int	outfile;

	j = 2;
	infile = open(argv[1], O_RDONLY, 0777);
	if (infile < 0)
		return (print_errors("open failed\n"));
	dup2(infile, STDIN_FILENO);
	if (argc > 4)
	{
		while (j != argc - 2)
		{
			if ((parse_arguments(argv[j], envp)))
				return (print_errors("parse_error\n"));
			j++;
		}
		close(infile);
		outfile = open(argv[argc - 1], O_WRONLY, 0777);
		if (outfile < 0)
			return (print_errors("open outfile error\n"));
		exec_last_cmd(outfile, argv[argc - 2], envp);
	}
}
