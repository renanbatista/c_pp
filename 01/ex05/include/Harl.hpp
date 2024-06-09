#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

const std::string RESET  = "\033[0m";
const std::string RED    = "\033[31;1m";
const std::string GREEN  = "\033[32;1m";
const std::string YELLOW = "\033[33;1m";
const std::string BLUE   = "\033[34;1m";
const std::string PURPLE = "\033[35;1m";
const std::string CYAN   = "\033[36;1m";
const std::string GRAY   = "\033[37;1m";

class Harl
{
  public:
	Harl(void);
	~Harl(void);
    void complain(std::string level);

  private:
    void debug(void);
    void info(void);
    void warning(void);
    void error(void);
};

#endif // HARL_HPP
