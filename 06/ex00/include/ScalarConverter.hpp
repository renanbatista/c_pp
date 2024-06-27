#ifndef _SCALARCONVERTER_HPP_
#define _SCALARCONVERTER_HPP_

#include <float.h>
#include <limits.h>

#include <cerrno>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <cerrno>
#include <cmath>
#include <limits>

class ScalarConverter {
    public:
        static void convert(std::string param);

    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const& src);
        ~ScalarConverter();

        ScalarConverter& operator=(ScalarConverter const& input);
};

#endif
