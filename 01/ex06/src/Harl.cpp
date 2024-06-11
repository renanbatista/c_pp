#include "../include/Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void Harl::complain(std::string level)
{
    void (Harl::*funcPtr[])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            (this->*funcPtr[i])();
            return;
        }
    }
    std::cout << PURPLE << "Invalid level: " << level << std::endl;
}

void Harl::filter(std::string level)
{
    int         index    = -1;
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
        {
            index = i;
            break;
        }
    }

    switch (index)
    {
        case 0:
            debug();
            // fall through
        case 1:
            info();
            // fall through
        case 2:
            warning();
            // fall through
        case 3:
            error();
            break;
        default:
            std::cout << PURPLE << "[ Probably complaining about insignificant problems ]"
                      << std::endl;
    }
}

void Harl::debug(void)
{
    std::cout << GREEN << "[DEBUG] " << GRAY
              << "  I love having extra bacon for my "
                 "7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
              << std::endl;
}

void Harl::info(void)
{
    std::cout << CYAN << "[INFO] " << GRAY
              << "   I cannot believe adding extra bacon costs more money. You didn’t put enough "
                 "bacon in my burger! If you did, I wouldn’t be asking for more!"
              << std::endl;
}

void Harl::warning(void)
{
    std::cout << YELLOW << "[WARNING] " << GRAY
              << "I think I deserve to have some extra bacon for free. I’ve been coming for years "
                 "whereas you started working here since last month."
              << std::endl;
}

void Harl::error(void)
{
    std::cout << RED << "[ERROR] " << GRAY
              << "  This is unacceptable! I want to speak to the manager now." << std::endl;
}
