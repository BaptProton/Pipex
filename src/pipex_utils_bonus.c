/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 09:57:22 by proton            #+#    #+#             */
/*   Updated: 2026/02/17 11:58:32 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	print_errors(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(2, &str[i], 1);
	return (1);
}

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
