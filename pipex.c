/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:38:16 by proton            #+#    #+#             */
/*   Updated: 2024/04/12 16:36:05 by bproton          ###   ########.fr       */
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
	char	*path;
	int		status;

	if (pipe(fd) == -1)
		return (1);
	id = fork();
	if (id == -1)
		return (1);
	n_arg = ft_split(arg, ' ');
	if (!n_arg)
		return (1);
	if (id == -1)
		return (1);
	if (id == 0)
	{
		puts("1");
		fd[0] = open(input, O_RDONLY);
		path = find_path(envp);
		printf("path %s\n", path);
		if (fd < 0)
			return (1);
		// execve(path, n_arg, envp);
	}
	else
	{
		waitpid(id, &status, NULL);
		puts("2");
		close(fd[0]);
		write(fd[1], output, BUFFERSIZE);
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
