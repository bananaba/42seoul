/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:33:03 by balee             #+#    #+#             */
/*   Updated: 2022/01/16 16:33:06 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *str, int c)
{
	char	*ret;

	ret = 0;
	while (1)
	{
		if (*str == (char)c)
			ret = (char *)str;
		if (!*str)
			break ;
		str++;
	}
	return (ret);
}
