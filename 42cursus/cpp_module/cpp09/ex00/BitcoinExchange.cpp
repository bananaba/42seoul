/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:10:40 by balee             #+#    #+#             */
/*   Updated: 2023/03/28 16:48:28 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	printErr(std::string str)
{
	std::cout << "Error: " << str << std::endl;
	return (1);
}

int	printErr(std::string str1, std::string str2)
{
	std::cout << "Error: " << str1 << " => " << str2 << std::endl;
	return (1);
}

t_ymd	wrongDate(void)
{
	t_ymd	date = {0, 0, 0};

	return (date);
}

t_ymd	checkDate(std::string ymd)
{
	t_ymd	date = {0, 0, 0};
	int		len;
	int		pos[2] = {0};

	len = ymd.length();
	for (int i = 0; i < len; i++)
	{
		if (ymd[i] == '-')
		{
			if (i == 0)
				return (wrongDate());
			else if (pos[0] == 0)
				pos[0] = i;
			else if (pos[1] == 0)
				pos[1] = i;
			else
				return (wrongDate());
		}
		else if (isdigit(ymd[i]) == false)
			return (wrongDate());
		else
		{
			if (pos[0] == 0)
				date.year = date.year * 10 + ymd[i] - '0';
			else if (pos[1] == 0)
				date.month = date.month * 10 + ymd[i] - '0';
			else
				date.day = date.day * 10 + ymd[i] - '0';
		}
	}
	if (date.month > 12 || date.month < 1 || date.day > 31 || date.day < 1)
		return (wrongDate());
	else if (date.month == 2)
	{
		if (date.year % 400 == 0)
		{
			if (date.day > 29)
				return (wrongDate());
		}
		else if (date.year % 4 == 0 && date.year % 100 != 0)
		{
			if (date.day > 29)
				return (wrongDate());
		}
		else if (date.day > 28)
			return (wrongDate());
	}
	else if (((date.month <= 7 && date.month % 2 == 1)
		|| (date.month > 7 && date.month % 2 == 0)) && date.day > 31)
		return (wrongDate());
	else if (((date.month <= 7 && date.month % 2 == 0)
		|| (date.month > 7 && date.month % 2 == 1)) && date.day > 30)
		return (wrongDate());
	return (date);
}

void	printValue(t_ymd date, double value, std::string str, t_map &db)
{
	int	year, month, day;

	year = date.year;
	if (db.find(year) != db.end())
		month = date.month;
	else
	{
		while (year >= 0 && db.find(year) == db.end())
			year--;
		if (year < 0)
		{
			printErr("infomation before the Datebase.");
			return ;
		}
		month = 12;
	}
	if (db[year].find(month) != db[year].end())
		day = date.day;
	else
	{
		while (month > 1 && db[year].find(month) == db[year].end())
			month--;
		if (month == 2)
		{
			if (year % 400 == 0)
				day = 29;
			else if (year % 4 == 0 && date.year % 100 != 0)
				day = 29;
			else
				day = 28;
		}
		else if ((date.month <= 7 && date.month % 2 == 1)
			|| (date.month > 7 && date.month % 2 == 0))
			day = 31;
		else if ((date.month <= 7 && date.month % 2 == 0)
			|| (date.month > 7 && date.month % 2 == 1))
			day = 30;
	}
	if (db[year][month].find(day) == db[year][month].end())
		while (day > 1 && db[year][month].find(day) == db[year][month].end())
			day--;
	std::cout << str << " => " << value << " = " << db[year][month][day] * value << std::endl;
}

void	parseInput(std::ifstream &ifs, t_map &db)
{
	std::string				content;
	std::size_t				pos;
	t_ymd					date;
	double					value;
	char					*stop;

	while (std::getline(ifs >> std::ws, content))
	{
		if (content.compare("date | value") == 0)
			continue ;
		pos = content.find(" | ");
		if (pos == std::string::npos)
		{
			printErr("bad input", content);
			continue ;
		}
		date = checkDate(content.substr(0, pos));
		if (date.year == 0 || date.month == 0 || date.day == 0)
		{
			printErr("bad input", content.substr(0, pos));
			continue ;
		}
		value = std::strtod((content.substr(pos + 3)).c_str(), &stop);
		if (*stop != 0)
			printErr("bad input", content);
		else if (value < 0)
			printErr("not a positive number.");
		else if (value > 1000)
			printErr("too large number.");
		else
			printValue(date, value, content.substr(0, pos), db);
	}
}

void	parseDB(t_map &db, std::ifstream &ifs)
{
	std::string				content;
	std::size_t				pos;
	t_ymd					date;
	double					value;
	char					*stop;
	
	while (std::getline(ifs >> std::ws, content))
	{
		if (content.compare("date,exchange_rate") == 0)
			continue ;
		pos = content.find(",");
		if (pos == std::string::npos)
		{
			printErr("bad database", content);
			continue ;
		}
		date = checkDate(content.substr(0, pos));
		if (date.year == 0 || date.month == 0 || date.day == 0)
		{
			printErr("bad database", content);
			continue ;
		}
		value = std::strtod((content.substr(pos + 1, content.length() - pos)).c_str(), &stop);
		if (*stop != 0)
		{
			printErr("bad database", content);
			continue ;
		}
		db[date.year][date.month][date.day] = value;
	}
}
