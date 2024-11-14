#include "Serialization.hpp"

uintptr_t	Serializer::serialize(Data *ptr)
{
	uintptr_t	new_ptr;

	new_ptr = reinterpret_cast<uintptr_t>(ptr); //reinterpret_cast lets you change the type of data and lets you come back to the same type of data and with the same values in the future
	return (new_ptr);
}

Data		*Serializer::deserialize(uintptr_t raw)
{
	Data	*new_ptr;

	new_ptr = reinterpret_cast<Data*>(raw);
	return (new_ptr);
}