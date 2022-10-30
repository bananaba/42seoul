/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mc_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 07:15:20 by snoh              #+#    #+#             */
/*   Updated: 2022/10/26 06:37:12 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmc.h"

static void	strcpy_c(char *dst, const char *src, char c)
{
	int	a;

	a = 0;
	while (src[a] && src[a] - c)
	{
		dst[a] = src[a];
		a++;
	}
	dst[a] = 0;
}

static int	strlen_c(const char *s, char c)
{
	int	a;

	a = 0;
	while (s[a] && s[a] - c)
	{
		a++;
	}
	return (a);
}

static char	*strdup_c(const char *s, char c)
{
	char	*r;

	r = mc_calloc(sizeof(char), strlen_c(s, c) + 1);
	if (r)
		strcpy_c(r, s, c);
	return (r);
}

static int	checklen(const char *s, char c)
{
	int		i;
	int		ca;

	i = -1;
	ca = 0;
	while (s[++i])
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			ca++;
	return (ca);
}

char	**mc_split(char const *s, char c)
{
	int		i;
	int		ca;
	char	**r;

	r = mc_calloc(sizeof(char *), checklen(s, c) + 1);
	if (r)
	{
		i = -1;
		ca = 0;
		while (s[++i])
		{
			if (s[i] != c && (i == 0 || s[i - 1] == c))
			{
				r[ca] = strdup_c(&s[i], c);
				if (!r[ca++])
				{
					while (--ca >= 0)
						mc_free(r[ca]);
					mc_free(r);
					return (0);
				}
			}
		}
	}
	return (r);
}
