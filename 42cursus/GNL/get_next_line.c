/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:21:11 by balee             #+#    #+#             */
/*   Updated: 2022/05/29 04:50:57 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_newline(char *buf)
{
	int	index;

	index = 0;
	while (buf && buf[index])
	{
		if (buf[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

char	*add_line(char *buf, char **line, int index, int status)
{
	char	*temp;

	temp = 0;
	if (buf && index >= 0)
	{
		temp = ft_strdup(buf + index + 1);
		buf[index] = 0;
	}
	*line = ft_strjoin(*line, buf);
	if (buf && status == BACKUP)
		free(buf);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;
	char		buf[BUFFER_SIZE + 1];
	int			index;
	int			read_len;

	line = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	index = is_newline(backup);
	backup = add_line(backup, &line, index, BACKUP);
	if (index != -1)
		return (ft_strjoin(line, "\n"));
	read_len = read(fd, buf, BUFFER_SIZE);
	while (index > 0)
	{
		buf[index] = 0;
		index = is_newline(buf);
		backup = add_line(buf, &line, index, BUF);
		if (index != -1)
			return (ft_strjoin(line, "\n"));
		read_len = read(fd, buf, BUFFER_SIZE);
	}
	return (line);
}
