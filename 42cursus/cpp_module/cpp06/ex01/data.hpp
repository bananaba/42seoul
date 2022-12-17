/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: balee <balee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:07:38 by balee             #+#    #+#             */
/*   Updated: 2022/12/17 14:07:39 by balee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <string>
# include <iostream>

struct Data
{
	std::string	_name;
	int			_age;
	std::string	_mdti;
};

uintptr_t serialize(Data* ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data *>(raw));
}

std::ostream &			operator<<( std::ostream & o, Data const & i )
{
	o << "Address: " << &i << ", Name: "<< i._name << ", Age: " << i._age << ", MBTI: " << i._mdti;
	return o;
}

#endif /* ************************************************************ DATA_H */