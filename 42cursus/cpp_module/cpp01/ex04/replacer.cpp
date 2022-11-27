/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:21:52 by balee             #+#    #+#             */
/*   Updated: 2022/11/27 21:21:53 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replacer.hpp"

void	replaceStr(std::string &content, std::string s1, std::string s2)
{
	int		len1;
	int		len2;
	size_t	i;

	len1 = s1.length();
	len2 = s2.length();
	i = 0;
	while (true)
	{
		i = content.find(s1, i);
		if (i == std::string::npos)
			return ;
		content.erase(i, len1);
		content.insert(i, s2);
		i += len2 + 1;
	}
}

int	exitErr(std::string str)
{
	std::cerr << "Error: " << str << std::endl;
	return (1);
}
