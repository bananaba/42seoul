#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <cctype>
# include <list>
# include <vector>
# include <iterator>
# include <iomanip>
# include <ctime>
# include <sys/time.h>

# define THRESHOLD_MAX 10

struct t_data
{
	int					num;
	std::vector<int>	before;
	std::vector<int>	after;
	double				listTime;
	double				vectorTime;
}	;

std::vector<int>	mergeInsertSort(std::vector<int> &before, int begin, int end, t_data &data);

#endif /* ******************************************************** PMERGEME_H */