/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:07:35 by balee             #+#    #+#             */
/*   Updated: 2022/12/17 16:33:41 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
# define SCALAR_HPP

# include <iostream>
# include <string>
# include <cmath>
# include <limits>
# include <cfloat>

void	convert(const std::string& input)
{
	std::string specialTypes[] = {"-inff", "+inff", "inff", "nanf", "-inf", "+inf", "inf", "nan"};
	std::string	toChar = "";
	int			toInt = 0;
	float		toFloat = 0;
	double		toDouble = 0;

	if (!std::isdigit(input[0]) && input.size() == 1 && std::isprint(input[0]))
	{
		toChar = input[0];
		std::cout << "char: " << toChar << std::endl;
		std::cout << "int: " << static_cast<int>(toChar[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(toChar[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(toChar[0]) << ".0" << std::endl;
		return ;
	}

	toInt = std::atoi(input.c_str());

	if (input[input.length() - 1] == 'f')
	{
		toFloat = std::atof(input.c_str());
		toDouble = static_cast<double>(toFloat);
	}
	else
	{
		toDouble = std::atof(input.c_str());
		toFloat = static_cast<float>(toDouble);
	}

	for (int i = 0; i < 8; ++i)
		if (input == specialTypes[i])
		{
			toChar = "imposible";
			break ;
		}
	if (toChar.empty() && std::isprint(toInt))
	{
		toChar = "'";
		toChar += static_cast<char>(toInt);
		toChar += "'";
	}
	else if (toChar.empty())
	{
		toChar = "Non displayable";
	}

	std::cout << "char: " << toChar << std::endl;

	if (toChar == "imposible")
		std::cout << "int: imposible" << std::endl;
	else
		std::cout << "int: " << toInt << std::endl;

	if (toChar != "imposible" && toFloat - static_cast<int>(toFloat) == 0) {
		std::cout << "float: " << toFloat << ".0f" << std::endl;
		std::cout << "double: " << toDouble << ".0" << std::endl;
	} else {
		std::cout << "float: " << toFloat << "f" << std::endl;
		std::cout << "double: " << toDouble << std::endl;
	}
}

#endif /* ********************************************************** SCALAR_H */