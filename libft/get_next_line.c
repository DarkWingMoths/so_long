/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagnon <mgagnon@student.42quebec.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:16:34 by mgagnon           #+#    #+#             */
/*   Updated: 2022/11/23 10:26:54 by mgagnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_line_out(char *store)
{
	int		i;
	char	*line;

	i = 0;
	if (!store[i])
		return (NULL);
	while (store[i] && store[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(char));
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
		/* line[i] = '\n'; */
		i++;
	}
	line[i - 1] = '\0';
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
	new_store = ft_calloc((ft_strlen(store) - i + 1),sizeof(char));
	if (!new_store)
		return (NULL);
	i++;
	while (store[i])
		new_store[j++] = store[i++];
	new_store[j] = '\0';
	free(store);
	return (new_store);
}

char	*read_and_save(int fd, char *save)
{
	int			read_bytes;
	char	*buff;

	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(save, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free (buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		save = ft_strjoin(save, buff);
	}
	if (buff[0])
		free (buff);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*store[257];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	store[fd] = read_and_save(fd, store[fd]);
	line = get_line_out(store[fd]);
	store[fd] = keep_the_rest(store[fd]);
	return (line);
}
