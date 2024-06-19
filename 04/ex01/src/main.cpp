#include "../include/Animal.hpp"
#include "../include/Brain.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

int main() {
    std::cout << BLUE << std::endl << "-----> BRAIN TEST" << std::endl;
    std::cout << WHITE << std::endl << "Create 10 animals." << std::endl << std::endl;

    const Animal *animals[10];

    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0)
            animals[i] = new Cat();
        else
            animals[i] = new Dog();
    }

    if (animals[4]->getType() == "Cat") {
        Cat copyCat((Cat &)*animals[4]);

        std::cout << YELLOW << "\nSound: ";
        copyCat.makeSound();

        std::cout << CYAN << "Idea 42: " << copyCat.getIdea(42) << std::endl << std::endl << RESET;

    } else
        std::cout << "Animals[4] is not of type Cat." << std::endl;

    std::cout << YELLOW << "## Animal[4] Start: " << std::endl << RESET;
    std::cout << MAGENTA << "Type: " << animals[4]->getType() << std::endl;

    std::cout << YELLOW << "\nSound: ";
    animals[4]->makeSound();

    std::cout << CYAN << "Idea 42: " << ((Cat *)animals[4])->getIdea(42) << std::endl;
    std::cout << RESET << std::endl;

    std::cout << YELLOW << "## Animal[4] Finished " << std::endl << std::endl << RESET;

    std::cout << "---> Deleting the Animal array." << std::endl;

    for (int i = 0; i < 10; ++i)
        delete animals[i];

    std::cout << std::endl << WHITE << "------> TESTE PART 2" << std::endl;
    std::cout << WHITE << "Creating a new Cat and a new Dog." << std::endl;

    Cat snow;
    Dog billy;

    {
        std::cout << WHITE << "## Copy operator Start." << std::endl;
        Cat cat2 = snow;
        Dog dog2 = billy;

        std::cout << std::endl;
        snow.makeSound();
        std::cout << MAGENTA << "Idea 10: " << snow.getIdea(10) << std::endl;

        std::cout << std::endl;
        billy.makeSound();
        std::cout << MAGENTA << "Idea 10: " << billy.getIdea(10) << std::endl;
        std::cout << std::endl;
    }
    std::cout << WHITE << "## Copy operator Finished." << std::endl;

    std::cout << YELLOW << std::endl << "Sound: ";
    snow.makeSound();

    std::cout << MAGENTA << "Idea 10: " << snow.getIdea(10) << std::endl;

    std::cout << YELLOW << "\nSound: ";
    billy.makeSound();

    std::cout << MAGENTA << "Idea 10: " << billy.getIdea(10) << std::endl;
    std::cout << RESET;

    std::cout << CYAN << "Call destructor" << std::endl << RESET;
    return 0;
}