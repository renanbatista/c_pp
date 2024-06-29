/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 11:15:48 by macarval          #+#    #+#             */
/*   Updated: 2024/05/10 14:20:07 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void) {
    std::srand(static_cast<unsigned int>(std::time(0)));
    std::cout << MAGENTA << "-----> ITER TESTS" << std::endl;
    std::cout << CYAN << "INT TEST" << RESET << std::endl;
    {
        int    arr[] = {1, 2, 3, 4, 5};
        size_t size = sizeof(arr) / sizeof(arr[0]);

        ::iter(arr, size, &colors<int>);
        std::cout << std::endl;
    }
    std::cout << CYAN << "STRING TEST" << RESET << std::endl;
    {
        std::string arr[] = {"one", "two", "three", "four", "five"};
        size_t      size = sizeof(arr) / sizeof(arr[0]);

        ::iter(arr, size, &debug<std::string>);
        std::cout << std::endl;
    }

    std::cout << CYAN << "FLOAT TEST" << RESET << std::endl;
    {
        float  arr[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
        size_t size = sizeof(arr) / sizeof(arr[0]);

        ::iter(arr, size, &colors<float>);
        std::cout << std::endl;
    }
    std::cout << MAGENTA << "-----> END OF ITER TESTS" << RESET << std::endl;
    return 0;
}