/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:38:16 by proton            #+#    #+#             */
/*   Updated: 2024/04/10 16:11:12 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parse_arguments(char *input, char *arg, char *output, char **envp)
{
	int	fd[2];

	fd[1] = open(input, );
	pipe(fd[1]);
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
