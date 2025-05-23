#include "Data.hpp"
#include "Serializer.hpp"

int main() {
	Data data;
	data.str = "Hello";
	data.num = 42;

	std::cout << "Original address: " << &data << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized value: " << raw << std::endl;

	Data* deserialized = Serializer::deserialize(raw);
	std::cout << "Deserialized address: " << deserialized << std::endl;

	std::cout << "Data content: " << deserialized->str << ", " << deserialized->num << std::endl;

	return 0;
}
