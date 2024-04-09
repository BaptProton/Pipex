/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:38:16 by proton            #+#    #+#             */
/*   Updated: 2024/04/09 15:59:46 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parse_arguments(char *arg1, char *arg2)
{
	char	**str1;
	char	**str2;

	str1 = ft_split(arg1, ' ');
	str2 = ft_split(arg2, ' ');
	
}

char	*open_input_file(const char *str)
{
	int		fd;
	char	*new;
	int		check;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		perror("1");
		return (NULL);
	}
	new = malloc(sizeof(char) * BUFFERSIZE);
	if (!new)
		return (NULL);
	check = read(fd, new, BUFFERSIZE);
	if (check < 0)
	{
		free(new);
		return (NULL);
	}
	new[check] = '\0';
	return (new);
}

int	main(int argc, char **argv)
{
	char	*input;

	if (argc == 4)
	{
		input = open_input_file(argv[1]);
		if (!input)
			return (1);
		if (!parse_arguments(argv[3], argv[4]));
		{
			free(input);
			return (1);
		}
	}
	else
		(void)input;
}
