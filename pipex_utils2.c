/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:49:56 by bproton           #+#    #+#             */
/*   Updated: 2024/04/19 09:05:33 by proton           ###   ########.fr       */
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
