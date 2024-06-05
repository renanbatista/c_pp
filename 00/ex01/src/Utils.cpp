#include "../include/Utils.hpp"

bool
all_is_digits(const std::string& input)
{
    for (std::string::const_iterator it = input.begin(); it != input.end(); ++it)
    {
        if (!std::isdigit(*it))
        {
            return false;
        }
    }
    return true;
}
