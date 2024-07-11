#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

#include "format.hpp"

class BitcoinExchange {
    private:
        std::map<std::string, float> _rates;

        void  loadDataBase();
        void  processDataBase(std::ifstream& file);
        void  checkHeader(const std::string& header, int type);
        void  trim(std::string& str);
        bool  isValidDate(const std::string& date);
        bool  isValidValue(const std::string& str, float& value);
        float getRate(const std::string& date);

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);

        void start(const std::string& fileName);
};

#endif
