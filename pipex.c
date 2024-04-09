/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:38:16 by proton            #+#    #+#             */
/*   Updated: 2024/04/09 09:41:28 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*open_input_file(const char *str)
{
	int		fd;
	char	*new;
	int		check;

	fd = open(str, O_RDONLY);
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

	if (argc == 2)
	{
		input = open_input_file(argv[1]);
		if (!input)
			return (1);
		get_token
	}
	else
		(void)input;
}
