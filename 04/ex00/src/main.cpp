#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
    std::cout << BLUE << std::endl;
    std::cout << "----------> SUBJECT TEST\n";
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << std::endl;
    std::cout << i->getType() << std::endl;

    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << BLUE << std::endl << "----------> WRONG ANIMALS TESTS" << std::endl;

    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << wrongCat->getType() << std::endl;
    wrongCat->makeSound();
    wrongAnimal->makeSound();

    delete meta;
    delete j;
    delete i;
    delete wrongAnimal;
    delete wrongCat;

    return 0;
}