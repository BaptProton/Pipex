/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:38:16 by proton            #+#    #+#             */
/*   Updated: 2024/04/18 16:06:47 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*research_path(char *path, char *cmd)
{
	int		j;
	char	**cmd_path;
	char	*temp;

	cmd_path = ft_split_path(path + 5, ':');
	j = -1;
	while (cmd_path[++j])
	{
		temp = ft_strjoin(cmd_path[j], cmd);
		if (access(temp, F_OK | X_OK) == 0)
			return (temp);
		free(temp);
	}
	j = -1;
	while (cmd_path[++j])
		free(cmd_path[j]);
	free(cmd_path);
	return (NULL);
}

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

// int	parse_arguments(char *input, char *arg, char *output, char **envp)
// {
// 	int		fd[2];
// 	int		id;
// 	char	**n_arg;
// 	char	*path;
// 	int		status;
// 	int		intxt;
// 	int		outxt;
// 	int		pid;
// 	char	*arg1[3];

// 	arg1[0] = "rev";
// 	// arg1[1] = "";
// 	arg1[1] = NULL;
// 	n_arg = ft_split(arg, ' ');
// 	// printf("1\n");
// 	if (pipe(fd) == -1)
// 		return (1);
// 	id = fork();
// 	if (id == -1)
// 		return (1);
// 	if (id == 0)
// 	{
// 		close(fd[0]);
// 		intxt = open(input, O_RDONLY);
// 		if (intxt < 0)
// 		return (1);
// 		// puts("2");
// 		dup2(intxt, STDIN_FILENO);
// 		dup2(fd[1], STDOUT_FILENO);
// 		path = find_path(envp, n_arg[0]);
// 		if (!path)
// 			exit(127);
// 		if (execve(path, n_arg, envp) == -1)
// 			exit(EXIT_FAILURE);
// 		close(fd[1]);
// 		close(intxt);
// 		exit(EXIT_FAILURE);
// 	}
// 	pid = fork();
// 	if (pid == -1)
// 		return (1);
// 	if (pid == 0)
// 	{
// 		close(fd[1]);
// 		waitpid(id, &status, 0);
// 		outxt = open(output, O_WRONLY);
// 		if (outxt < 0)
// 			return (1);
// 		// puts("3");
// 		dup2(fd[0], STDIN_FILENO);
// 		dup2(outxt, STDOUT_FILENO);
// 		path = find_path(envp, arg1[0]);
// 		if (!path)
// 			exit(127);
// 		if (execve(path, arg1, envp) == -1)
// 			exit(EXIT_FAILURE);
// 		close(fd[0]);
// 		close(outxt);
// 		exit(EXIT_FAILURE);
// 	}
// 	else
// 	{
// 		// waitpid(id, &status, 0);
// 		waitpid(pid, &status, 0);
// 		close(fd[0]);
// 		close(fd[1]);
// 		exit(EXIT_SUCCESS);
// 	}
// 	return (0);
// }

int make_cmd(char *arg, char **envp)
{
	char	*path;
	char	**n_arg;

	n_arg = ft_split(arg, ' ');
	path = find_path(envp, arg);
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
	else if (pid == 0)
	{
		child_process(fd);
		if (make_cmd(arg, envp))
			exit(127);
		puts("2");
		exit(EXIT_SUCCESS);
	}
	else
	{
		waitpid(pid, &status, 0);
		close(fd[1]);
		parent_process(fd, pid);
		return (status);
	}
	
}

int	main(int argc, char **argv, char **envp)
{
	int	j;
	int	fd;
	int	outfile;

	j = 2;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (print_errors("open failed\n"));
	dup2(fd, STDIN_FILENO);
	if (argc > 4)
	{
		while (j != argc - 2)
		{
			if (!(parse_arguments(argv[j], envp)))
				return (print_errors("parse_error\n"));
			j++;
		}
		outfile = open(argv[argc], O_WRONLY);
		if (outfile < 0)
			return (print_errors("open outfile error\n"));
		exec_last_cmd()
	}
}
