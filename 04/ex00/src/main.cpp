#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {
    std::cout << BLUE << std::endl;
    std::cout << "----------> SUBJECT TEST\n";
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << dog->getType() << std::endl;
    std::cout << cat->getType() << std::endl;

    cat->makeSound();
    dog->makeSound();
    meta->makeSound();

    std::cout << BLUE << std::endl << "----------> WRONG ANIMALS TESTS" << std::endl;

    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();
    std::cout << wrongCat->getType() << std::endl;
    wrongCat->makeSound();
    wrongAnimal->makeSound();

    delete meta;
    delete dog;
    delete cat;
    delete wrongAnimal;
    delete wrongCat;

    return 0;
}