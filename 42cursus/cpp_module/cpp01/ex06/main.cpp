/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:22:25 by balee             #+#    #+#             */
/*   Updated: 2022/11/27 21:22:26 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl		harl;

	if (argc != 2)
	{
		std::cerr << "Usage: ./harlFilter <filter>" << std::endl;
		return (1);
	}
	harl.harlFilter(argv[1]);
	return (0);
}
