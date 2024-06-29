#include "Data.hpp"
#include "Serializer.hpp"

int main(void) {
    std::cout << MAGENTA << "----> REINTERPRET CAST TEST" << std::endl << RESET;
    std::cout << "Data(42, \"Database\")" << std::endl << RESET;

    Data *data = new Data(42, "Database");
    std::cout << "Data is in pointer: \t\t" << MAGENTA << data << std::endl;
    std::cout << *data;

    std::cout << CYAN << "Serializing::serialize(data)" << std::endl << RESET;

    uintptr_t convertedPointer = Serializer::serialize(data);
    std::cout << "Int pointer is: \t\t" << convertedPointer << std::endl;

    std::cout << CYAN << "Deserializing convertedPointer pointer using reinterpret_cast." << std::endl << RESET;
    std::cout << "Serializer::deserialize(convertedPointer)" << std::endl;

    Data *after = Serializer::deserialize(convertedPointer);
    std::cout << "Data is still pointing at: \t" << MAGENTA << after << std::endl;
    std::cout << *after;

    delete data;

    std::cout << MAGENTA << "----> END OF TEST" << RESET << std::endl;

    return 0;
}