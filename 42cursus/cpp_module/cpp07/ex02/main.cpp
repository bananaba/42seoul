#include <iostream>
#include <string>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

	// Array<std::string>	str1(5);
	// Array<std::string>	str2;

	// str1[0] = "balee";
	// str1[1] = " hates";
	// str1[2] = " cpp";
	// str1[3] = " modulo";
	// str1[4] = " subjects";

	// for (int i = 0; i < 5; i++)
	// 	std::cout << str1[i];
	// std::cout << std::endl;
	
	// str2 = str1;
	// str2[1] = " loves";

	// for (int i = 0; i < 5; i++)
	// 	std::cout << str1[i];
	// std::cout << std::endl;
	// for (int i = 0; i < 5; i++)
	// 	std::cout << str2[i];
	// std::cout << std::endl;

    return 0;
}