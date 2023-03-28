/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:11:08 by balee             #+#    #+#             */
/*   Updated: 2023/03/27 15:11:09 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	reversePolishNotation(std::string str)
{
	std::stack<double>	st;
	int					i;
	double				num[2];
	double				result;

	i = 0;
	while (str[i] != 0)
	{
		while (isspace(str[i]))
			i++;
		if (isdigit(str[i]) != false)
			st.push(str[i++] - '0');
		else if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*')
		{
			if (st.empty())
			{
				std::cout << "Error: wrong formula" << std::endl;
				return (1);
			}
			num[1] = st.top();
			st.pop();
			if (st.empty())
				num[0] = 0;
			else
			{
				num[0] = st.top();
				st.pop();
			}
			if (str[i] == '+')
				st.push(num[0] + num[1]);
			else if (str[i] == '-')
				st.push(num[0] - num[1]);
			else if (str[i] == '*')
				st.push(num[0] * num[1]);
			else
			{
				if (num[1] == 0)
				{
					std::cout << "Error: wrong formula" << std::endl;
					return (1);
				}
				else
					st.push(num[0] / num[1]);
			}
		}
		else
		{
			std::cout << "Error: unknown operation" << std::endl;
			return (1);
		}
		i++;
	}
	result = st.top();
	st.pop();
	if (st.empty())
		std::cout << result << std::endl;
	else
	{
		std::cout << "Error: wrong fomula" << std::endl;
		return (1);
	}
	return (0);
}
