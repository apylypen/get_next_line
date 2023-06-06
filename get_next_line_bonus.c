/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:49:05 by apylypen          #+#    #+#             */
/*   Updated: 2023/06/01 16:07:07 by apylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_file(int fd, char *str)
{
	char	*buff;
	int		b_count;

	b_count = 1;
	buff = malloc(sizeof(char) *(BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (b_count != 0 && !ft_strchr(str, '\n'))
	{
		b_count = read(fd, buff, BUFFER_SIZE);
		if (b_count == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[b_count] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*get_line(char *str)
{
	char	*l;
	int		i;

	if (!*str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	l = malloc(sizeof(char) * (i + 2));
	if (!l)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		l[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		l[i] = str[i];
		i++;
	}
	l[i] = '\0';
	return (l);
}

char	*next_line(char *str)
{
	char	*l;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	l = malloc(sizeof(char) * (ft_strlen(str) + 1 - i));
	if (!l)
		return (NULL);
	i++;
	while (str[i])
		l[j++] = str[i++];
	l[j] = '\0';
	free(str);
	return (l);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*l;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = read_file(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	l = get_line(str[fd]);
	str[fd] = next_line(str[fd]);
	return (l);
}
