#include "PmergeMe.hpp"
#include <ios>

void	printResult(t_data &data)
{
	std::cout << "before:	";
	for (int i = 0; i < data.num; i++)
	{
		std::cout << data.before[i];
		if (i != data.num - 1)
			std::cout << " ";
		else
			std::cout << std::endl;
	}
	std::cout << "after:	";
	for (int i = 0; i < data.num; i++)
	{
		std::cout << data.after[i];
		if (i != data.num - 1)
			std::cout << " ";
		else
			std::cout << std::endl;
	}
	std::cout << "Time to process a range of " << std::setw(5) << data.num << " elements with std::list : ";
	std::cout << std::fixed << data.listTime << " us" << std::endl;
	std::cout << "Time to process a range of " << std::setw(5) << data.num << " elements with std::vector : ";
	std::cout << std::fixed << data.vectorTime << " us" << std::endl;
}

int	main(int argc, char **argv)
{
	t_data	data;
	clock_t	t;
	int		i;
	int		j;
	int		num;

	if (argc == 1)
	{
		std::cout << "Error: Usage: ./PmergeMe argv" << std::endl;
		return (1);
	}
	i = 1;
	data.num = argc - 1;
	data.listTime = 0;
	data.vectorTime = 0;
	t = clock();
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != 0 && isdigit(argv[i][j]) == true)
			j++;
		if (argv[i][j] != 0)
		{
			std::cout << "Error: Invalid argument" << std::endl;
			return (1);
		}
		num = atoi(argv[i]);
		data.before.push_back(num);
		i++;
	}
	data.vectorTime += static_cast<double>(clock() - t) / CLOCKS_PER_SEC * 1000000;
	data.after = mergeInsertSort(data.before, 0, data.before.size(), data);
	printResult(data);
	return (0);
}
