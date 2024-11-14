#include "Serialization.hpp"

int main() {
    // Create a Data object
    Data data;
    data.id = 42;
    data.name = "juanmanuel";
	data.surnames = "rey rojas";
	data.telephone = 637605118;
	data.age = 24;

    // Serialize the pointer to Data
    uintptr_t raw = Serializer::serialize(&data);

    // Deserialize the uintptr_t back to a Data pointer
    Data* deserializedData = Serializer::deserialize(raw);

    // Check if the deserialized pointer matches the original

    std::cout << "Original Data pointer: " << &data << std::endl;
	std::cout << "Original data name: " << data.name << std::endl;
	std::cout << "Original Serialize pointer: " << raw << std::endl;
    std::cout << "Deserialized Data pointer: " << deserializedData << std::endl;
	std::cout << "Deserialized data name: " << deserializedData->name << std::endl << std::endl;

    // Verify that the data members match
    if (deserializedData == &data) {
        std::cout << "Deserialization successful!" << std::endl;
        std::cout << "ID: " << deserializedData->id << ", Name: " << deserializedData->name << std::endl;
    } else {
        std::cout << "Deserialization failed." << std::endl;
    }

    return 0;
}