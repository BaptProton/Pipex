/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:38:16 by proton            #+#    #+#             */
/*   Updated: 2024/04/10 10:01:48 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parse_arguments(char *input, char *arg1, char *arg2, char *output)
{
	char	**str1;
	char	**str2;
	int		pid;

	if (!(str1 = ft_split(arg1, ' ')))
		return (0);
	if (!(str2 = ft_split(arg2, ' ')))
		return (0);
	pid = fork();
	
	
	
}

// char	*open_input_file(const char *str)
// {
// 	int		fd;
// 	char	*new;
// 	int		check;

// 	fd = open(str, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("1");
// 		return (NULL);
// 	}
// 	new = malloc(sizeof(char) * BUFFERSIZE);
// 	if (!new)
// 		return (NULL);
// 	check = read(fd, new, BUFFERSIZE);
// 	if (check < 0)
// 	{
// 		free(new);
// 		return (NULL);
// 	}
// 	new[check] = '\0';
// 	return (new);
// }

int	main(int argc, char **argv)
{
	char	**arg1;
	char	**arg2;

	if (argc == 5)
	{
		
		if (!parse_arguments(argv[1], argv[2], argv[3], argv[4]));
			return (1);
	}
}
