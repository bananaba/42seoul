/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:21:11 by balee             #+#    #+#             */
/*   Updated: 2022/05/28 04:25:20 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_newline(char *buf)
{
	int	index;

	index = 0;
	while (buf[index])
	{
		if (buf[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

char	*add_line(char **buf, char **line, int index, int status)
{
	char	*temp;
	int		len;

	if (index == -1)
		index = ft_strlen(*buf);
	(*buf)[index] = 0;
	*line = ft_strjoin(line, *buf);
	if (index != ft_strlen(*buf))
	{
		len = ft_strlen(*buf + index + 1);
		if (len == 0)
		{
			if (status == BACKUP)
				free(*buf);
			return (0);
		}
		temp = ft_strdup(*buf + index + 1);
	}
	if (status == BACKUP)
		free(*buf);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		buf[BUFFER_SIZE];
	char		*line;
	int			index;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	if (backup && *backup)
	{
		index = is_newline(backup);
		backup = add_line(&backup, &line, index, BACKUP);
		if (index != -1)
			return (ft_strjoin(&line, "\n"));
	}
	while (read(fd, buf, BUFFER_SIZE) > 0)
	{
		index = is_newline(buf);
		backup = add_line(&buf, &line, index, BUF);
		if (index != -1)
			return (ft_strjoin(&line, "\n"));
	}
	return (line);
}
