/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:38:16 by proton            #+#    #+#             */
/*   Updated: 2024/04/17 16:05:14 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_strcat(char *dest, const char *s1)
{
	size_t	i;
	size_t	t;

	i = 0;
	t = 0;
	while (s1[i] != '\0')
	{
		dest[t + i] = s1[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	o;

	i = 0;
	o = ft_strlen(s1);
	if (!s1 || !s2)
		return (NULL);
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (s3 == NULL)
		return (NULL);
	s3 = ft_strcat(s3, s1);
	while (s2[i] != '\0')
	{
		s3[o] = s2[i];
		i++;
		o++;
	}
	s3[o] = '\0';
	return (s3);
}

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
		if (access(temp, F_OK && X_OK) == 0)
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

int	parse_arguments(char *input, char *arg, char *output, char **envp)
{
	int		fd[2];
	int		id;
	char	**n_arg;
	char	*path;
	int		status;
	int		intxt;
	int		outxt;
	int		pid;
	char	*arg1[3];
	int		test;

	arg1[0] = "ls";
	arg1[1] = "-l";
	arg1[2] = NULL;
	n_arg = ft_split(arg, ' ');
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
		path = find_path(envp, arg[0]);
		if (!path)
			exit(127);
		if (execve(path, n_arg, envp) == -1);
			exit(printf("exec 1 not running properly\n"));
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
		if (execve(path, , envp) == -1);
			exit(printf("exec 2 not running properly\n"));
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
