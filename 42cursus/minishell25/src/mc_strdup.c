/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mc_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 07:15:20 by snoh              #+#    #+#             */
/*   Updated: 2022/10/26 06:37:17 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmc.h"

char	*mc_strdup(const char *s1)
{
	char	*r;

	r = mc_calloc(sizeof(char), ft_strlen(s1) + 1);
	if (r)
		ft_strlcpy(r, s1, ft_strlen(s1) + 1);
	return (r);
}
