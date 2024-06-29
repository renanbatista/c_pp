#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/Base.hpp"
#include "../include/C.hpp"

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));
    std::cout << MAGENTA << "-----> DYNAMIC CAST TEST" << std::endl << RESET;

    for (int i = 0; i < 3; i++)
    {
        std::cout << CYAN << "TEST: " << i + 1 << std::endl;
        std::cout << YELLOW << "Base *base = generate()" << GRAY << std::endl;
        Base *base = generate();
        std::cout << std::endl;
        std::cout << YELLOW << "identify(base)" << GRAY << std::endl;
        identify(base);
        std::cout << std::endl;
        std::cout << YELLOW << "identify(*base)" << GRAY << std::endl;
        identify(*base);
        std::cout << std::endl;

        delete base;

        std::cout << CYAN << "FINISH TEST: " << i + 1 << std::endl << std::endl;
    }
    std::cout << MAGENTA << "-----> FINISH DYNAMIC CAST TEST" << std::endl;
    std::cout << RESET << std::endl;

    return 0;
}