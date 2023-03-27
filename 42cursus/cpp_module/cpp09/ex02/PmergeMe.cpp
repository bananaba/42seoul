#include "PmergeMe.hpp"
#include <ctime>

std::vector<int>	insertSort(std::list<int> &before)
{
	std::list<int>				after;
	std::vector<int>			result;
	std::list<int>::iterator	it[2];

	it[0] = before.begin();
	while (it[0] != before.end())
	{
		it[1] = after.begin();
		while (it[1] != after.end() && *it[0] >= *it[1])
			it[1]++;
		after.insert(it[1], *it[0]);
		it[0]++;
	}
	result = std::vector<int>(after.begin(), after.end());
	return (result);
}

std::vector<int>	mergeInsertSort(std::vector<int> &before, int begin, int end, t_data &data)
{
	clock_t				t;
	std::list<int>		newList;
	std::vector<int>	after(end - begin);
	std::vector<int>	left, right;
	int					i[2] = {0};
	int					mid;

	if (end - begin < THRESHOLD_MAX)
	{
		t = clock();
		newList = std::list<int>(std::next(before.begin(), begin), std::next(before.begin(), end));
		after = insertSort(newList);
		data.listTime += static_cast<double>(clock() - t) / CLOCKS_PER_SEC * 1000000;
	}
	else
	{
		mid = (begin + end) / 2;
		left = mergeInsertSort(before, begin, mid, data);
		right = mergeInsertSort(before, mid, end, data);
		t = clock();
		while (i[0] < mid - begin && i[1] < end - mid)
		{
			if (left[i[0]] < right[i[1]])
			{
				after[i[0] + i[1]] = left[i[0]];
				i[0]++;
			}
			else
			{
				after[i[0] + i[1]] = right[i[1]];
				i[1]++;
			}
		}
		while (i[0] < mid - begin)
		{
			after[i[0] + i[1]] = left[i[0]];
			i[0]++;
		}
		while (i[1] < end - mid)
		{
			after[i[0] + i[1]] = right[i[1]];
			i[1]++;
		}
		data.listTime += static_cast<double>(clock() - t) / CLOCKS_PER_SEC * 1000000;
	}
	return (after);
}
