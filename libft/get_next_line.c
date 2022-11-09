/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:16:34 by mgagnon           #+#    #+#             */
/*   Updated: 2022/11/02 14:12:13 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_line_out(char *store)
{
	int		i;
	char	*line;

	i = 0;
	if (!store)
		return (NULL);
	while (!store[i] && store[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (store[i] && store[i] != '\n')
	{
		line[i] = store[i];
		i++;
	}
	if (store[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*keep_the_rest(char *store)
{
	int		i;
	int		j;
	char	*new_store;

	i = 0;
	j = 0;
	while (store[i] && store[i] != '\n')
		i++;
	if (!store[i])
	{
		free(store);
		return (NULL);
	}
	new_store = malloc(sizeof(char) * (ft_strlen(store) - i + 1));
	if (!new_store)
		return (NULL);
	i++;
	while (store[i])
		new_store[j++] = store[i++];
	new_store[j] = '\0';
	free(store);
	return (new_store);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*store[FOPEN_MAX];
	int			read_bytes;

	read_bytes = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	while (!ft_strchr(store[fd], '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, line, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free (line);
			return (NULL);
		}
		line[read_bytes] = '\0';
		store[fd] = ft_strjoin(store[fd], line);
	}
	free (line);
	line = get_line_out(store[fd]);
	store[fd] = keep_the_rest(store[fd]);
	return (line);
}
