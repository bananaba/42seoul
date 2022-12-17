/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:07:41 by balee             #+#    #+#             */
/*   Updated: 2022/12/17 15:00:41 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	std::cout << "Data              : " << *data << std::endl;
	rawData = serialize(data);
	std::cout << "Raw data          : " << std::hex << rawData << std::dec << std::endl;
	retData = deserialize(rawData);
	std::cout << "Deserialized data : " << *retData << std::endl;
	retData->_age = 30;
	std::cout << "Data              : " << *data << std::endl;

	delete data;

	return (0);
}
