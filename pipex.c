/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:38:16 by proton            #+#    #+#             */
/*   Updated: 2024/04/17 10:25:53 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/// @brief function that search for the : PATH= pattern
/// @param envp envp from main
/// @return returns the PATH= whenever is finds it 
char	*find_path(char **envp)
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
				return (envp[j]);
		}
	}
	return (NULL);
}

/// @brief Function that parse arguments
/// @param input Is the input
/// @param arg Is the arg
/// @param output Is the output
/// @param envp Is the environment
/// @return Reutrn 0 or 1
int	parse_arguments(char *input, char *arg, char *output, char **envp)
{
	int		fd[2];
	int		id;
	char	**n_arg;
	// char	*path;
	int		status;
	int		intxt;
	int		outxt;
	int		pid;
	char	*arg1[3];
	int		test;

	arg1[0] = "ls";
	arg1[1] = "-l";
	arg1[2] = NULL;
	// path = find_path(envp);
	if (pipe(fd) == -1)
		return (1);
	id = fork();
	if (id == -1)
		return (1);
	if (id == 0)
	{
		close(fd[0]);
		intxt = open(input, O_RDONLY);
		if (intxt < 0)
		return (1);
		dup2(intxt, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		n_arg = ft_split(arg, ' ');
		printf("arg 1 %s\n", n_arg[0]);
		printf("arg 2 %s\n", n_arg[1]);
		// printf("arg %s \n", n_arg[2]);
		test = execve("/bin/wc", n_arg, envp);
		printf("test value %d\n", test);
		if (test == -1)
			printf("exec 1 not running properly\n");
		close(fd[1]);
		close(intxt);
	}
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		close(fd[1]);
		outxt = open(output, O_WRONLY);
		if (outxt < 0)
			return (1);
		dup2(outxt, STDOUT_FILENO);
		dup2(fd[0], STDIN_FILENO);
		printf("arg1 %s\n", arg1[0]);
		printf("arg1 %s\n", arg1[1]);
		test = execve("bin/ls", n_arg, envp);
		if (test == -1)
			printf("exec 2 not running properly\n");
		close(fd[0]);
		close(outxt);
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(id, &status, 0);
		waitpid(pid, &status, 0);
		close(fd[0]);
		close(fd[1]);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int	j;

	j = 2;
	if (argc > 4)
	{
		// while (argc != argc - 1)
		// {
			parse_arguments(argv[1], argv[j], argv[argc -1], envp);
		// 	j++;
		// }
	}
}
