/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:21:11 by balee             #+#    #+#             */
/*   Updated: 2022/07/02 04:24:00 by balee            ###   ########.fr       */
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

char	*add_line(char *buf, char **line, int *index, int status)
{
	char	*temp;

	temp = 0;
	*index = is_newline(buf);
	if (buf && *index >= 0)
	{
		temp = ft_strdup(buf + *index + 1);
		buf[*index] = 0;
	}
	*line = ft_strjoin(*line, buf);
	if (buf && status == BACKUP)
		free(buf);
	else if (buf && status == BUF)
		ft_memset(buf, 0, BUFFER_SIZE + 1);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;
	char		*buf;
	int			index;

	line = 0;
	backup = add_line(backup, &line, &index, BACKUP);
	if (index != -1)
		return (ft_strjoin(line, "\n"));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (line);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	ft_memset(buf, 0, BUFFER_SIZE + 1);
	while (index == -1 && read(fd, buf, BUFFER_SIZE))
		backup = add_line(buf, &line, &index, BUF);
	free(buf);
	if (index != -1)
		return (ft_strjoin(line, "\n"));
	return (line);
}
