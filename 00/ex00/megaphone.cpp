#include <iostream>

int main(int argc, char **argv)
{
    if (argc <= 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        std::string fullStr = "";

        for (int i = 1; i < argc; i++)
        {
            std::string str(argv[i]);
            for (unsigned int len = 0; len < str.size(); len++)
                str[len] = std::toupper(str[len]);
            std::cout << str;
        }
        std::cout << std::endl;
    }
}
