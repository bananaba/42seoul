/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:10:56 by balee             #+#    #+#             */
/*   Updated: 2023/03/28 16:47:55 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>
# include <cctype>
# include <cstdlib>

struct	t_ymd
{
	int		year;
	int		month;
	int		day;
};

typedef std::map< int, std::map< int, std::map< int, double> > >	t_map;

int		printErr(std::string str);
int		printErr(std::string str1, std::string str2);
t_ymd	wrongDate(void);
t_ymd	checkDate(std::string ymd);
void	printValue(t_ymd date, double value, std::string str, t_map &db);
void	parseInput(std::ifstream &ifs, t_map &db);
void	parseDB(t_map &db, std::ifstream &ifs);

#endif /* ************************************************* BITCOINEXCHANGE_H */