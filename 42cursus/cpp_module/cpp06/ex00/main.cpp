/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:07:17 by balee             #+#    #+#             */
/*   Updated: 2022/12/17 16:31:34 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scalar.hpp"

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "Error: no argument" << std::endl;
		return (1);
	}

	convert(argv[1]);

	return (0);
}
