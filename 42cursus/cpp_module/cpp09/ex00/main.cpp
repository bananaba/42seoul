/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 22:30:22 by balee             #+#    #+#             */
/*   Updated: 2023/03/27 03:14:41 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"	

int	main(int argc, char *argv[])
{
	t_map					database;
	std::ifstream			ifs1;
	std::ifstream			ifs2;

	if (argc != 2)
		return (printErr("could not open file."));
	ifs1.open("data.csv", std::ios_base::in);
	if (ifs1.fail())
		return (printErr("could not open database."));
	parseDB(database, ifs1);
	ifs1.close();
	ifs2.open(argv[1], std::ios_base::in);
	if (ifs2.fail())
		return (printErr("could not open file."));
	parseInput(ifs2, database);
	ifs2.close();
	return (0);
}
