/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mc_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 07:15:20 by snoh              #+#    #+#             */
/*   Updated: 2022/10/26 06:37:19 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmc.h"

char	*mc_strjoin(char const *s1, char const *s2)
{
	char	*r;

	r = mc_calloc(sizeof(char), ft_strlen(s1) + ft_strlen(s2) + 1);
	if (r)
	{
		ft_strlcpy(r, s1, ft_strlen(s1) + 1);
		ft_strlcat(r, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	}
	return (r);
}
