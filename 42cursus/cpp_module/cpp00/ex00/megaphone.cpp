/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:27:58 by balee             #+#    #+#             */
/*   Updated: 2022/11/22 18:47:48 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int	main(int argc, char **argv)
{
	int			i;
	int			j;
	std::string	str;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i = 1;
		while (i < argc)
		{
			str = argv[i];
			j = 0;
			while (j < (int)str.length())
				std::cout << static_cast<char>(std::toupper(str.at(j++)));
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}
