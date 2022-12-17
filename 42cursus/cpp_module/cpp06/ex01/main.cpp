#include "Data.hpp"
#include <iostream>

int	main(void)
{
	Data		*data;
	uintptr_t	rawData;
	Data		*retData;

	data = new Data;
	data->_name = "balee";
	data->_age = 25;
	data->_mdti = "INTP";

	std::cout << "Data             : " << *data << std::endl;
	rawData = serialize(data);
	std::cout << "Raw data         : " << rawData << std::endl;
	retData = deserialize(rawData);
	std::cout << "Deserialized data: " << *retData << std::endl;
	retData->_age = 30;
	std::cout << "Data             : " << *data << std::endl;

	delete data;

	return (0);
}
