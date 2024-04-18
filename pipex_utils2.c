/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:49:56 by bproton           #+#    #+#             */
/*   Updated: 2024/04/18 16:03:50 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child_process(int *fd)
{
	puts("child");
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	return (0);
}
int	parent_process(int *fd, int pid)
{
	(void)pid;

	puts("parent");
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	return (0);
}
