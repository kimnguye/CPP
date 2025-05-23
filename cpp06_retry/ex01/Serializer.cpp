#include "Serializer.hpp"

/*coplien*/

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &other) {(void) other;}

Serializer &Serializer::operator=(const Serializer &other)
{
	(void) other;
	return *this;
}

Serializer::~Serializer() {}

/*reinterpret_cast est utilisé pour convertir un type en un autre sans changer les bits*/

uintptr_t	Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*		Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

