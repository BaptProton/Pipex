/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:49:56 by bproton           #+#    #+#             */
/*   Updated: 2024/04/25 17:40:52 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parent_process(int *fd)
{
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	return (0);
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
