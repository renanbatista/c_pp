#include "../include/Animal.hpp"
#include "../include/Brain.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

int main() {
    Animal *array[100];
    int     i = 0;

    while (i < 50)
        array[i++] = new Dog();
    while (i < 100)
        array[i++] = new Cat();

    array[4]->makeSound();
    array[72]->makeSound();
    for (i = 0; i < 100; i++)
        delete array[i];

    return 0;
}