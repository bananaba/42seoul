#ifndef DATA_HPP_
# define DATA_HPP_

# include <cstdint>

struct Data {
	int n;
};

uintptr_t serialize(Data *ptr);

Data* deserialize(uintptr_t raw);

#endif