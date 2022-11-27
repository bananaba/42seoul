/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:21:37 by balee             #+#    #+#             */
/*   Updated: 2022/11/27 21:21:38 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replacer.hpp"

int	main(int argc, char **argv)
{
	std::ifstream		ifs;
	std::ofstream		ofs;
	std::string			content;
	std::stringstream	ss;

	if (argc != 4)
		return (exitErr("Usage: ./replacer <filename> s1 s2"));
	else if (argv[2][0] == '\0')
		return (exitErr("s1 is empty"));
	ifs.open(argv[1], std::ios_base::in);
	if (ifs.fail())
		return (exitErr("input file open fail"));
	ss << ifs.rdbuf();
	ifs.close();
	ofs.open(static_cast<std::string>(argv[1]) + ".replace", std::ios_base::out | std::ios_base::trunc);
	if (ofs.fail())
		return (exitErr("output file open fail"));
	content = ss.str();
	replaceStr(content, argv[2], argv[3]);
	ofs << content;
	ofs.close();
	return (0);
}
