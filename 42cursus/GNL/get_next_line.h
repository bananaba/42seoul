/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 04:26:30 by balee             #+#    #+#             */
/*   Updated: 2022/07/02 01:58:59 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef BACKUP
#  define BACKUP 0
# endif

# ifndef BUF
#  define BUF 1
# endif

size_t	ft_strlcpy(char *dest, char *src, size_t n);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char const *s2);
char	*add_line(char *buf, char **line, int *index, int status);
char	*get_next_line(int fd);
int		is_newline(char *buf);

#endif