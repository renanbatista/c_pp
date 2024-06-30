#ifndef _DATA_HPP_
#define _DATA_HPP_

#include <iostream>
#include "format.hpp"

class Data {
    private:
        int         _number;
        std::string _name;

    public:
        Data(void);
        Data(int index, std::string name);
        Data(Data const &copy);
        ~Data(void);
        Data       &operator=(Data const &other);
        int         getIndex(void) const;
        std::string getName(void) const;
        void        setIndex(int index);
        void        setName(std::string name);
};

std::ostream &operator<<(std::ostream &out, Data const &data);

#endif