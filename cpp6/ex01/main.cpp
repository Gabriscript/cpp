#include "Serializer.hpp"

int main()
{

    Data *originalData = new Data();
    originalData->name = "Mario";
    originalData->age = 33;
    
    std::cout << std::endl;
    std::cout << "  - Address: " << originalData << std::endl;
    std::cout << std::endl;

    std::cout << "Serializing pointer to uintptr_t" << std::endl;
    uintptr_t serializedValue = Serializer::serialize(originalData);
    
    std::cout << "  Pointer " << originalData << " becomes:" << std::endl;
    std::cout << "  - uintptr_t: " << serializedValue << std::endl;
    std::cout << std::endl;

    std::cout << "Deserializing uintptr_t back to pointer" << std::endl;
    Data* deserializedData = Serializer::deserialize(serializedValue);
    
    std::cout << "  Number " << serializedValue << " becomes:" << std::endl;
    std::cout << "  - pointer: " << deserializedData << std::endl;
    std::cout << std::endl;

    std::cout << "  Original pointer:     " << originalData << std::endl;
    std::cout << "  Deserialized pointer: " << deserializedData << std::endl;
    std::cout << std::endl;
    

    delete originalData;
    return 0;
}