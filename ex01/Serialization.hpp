#pragma once

#include <iostream>
#include <string>
#include <climits>  // For ULONG_MAX

typedef unsigned long long uintptr_t;

struct Data
{
	int	id;
	std::string	name;
	std::string surnames;
	long long	telephone;
	unsigned int	age;
};

class Serializer
{
	private:
		Serializer() {};
		Serializer(const Serializer &serializer) {(void)serializer;};
		Serializer	&operator=(const Serializer &serializer) {(void)serializer; return (*this);};
		~Serializer() {};

	public:
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);

};