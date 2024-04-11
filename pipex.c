/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:38:16 by proton            #+#    #+#             */
/*   Updated: 2024/04/10 18:24:07 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parse_arguments(char *input, char *arg, char *output, char **envp)
{
	int	fd[2];

	pipe(fd);
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
