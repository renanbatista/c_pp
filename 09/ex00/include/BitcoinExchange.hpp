#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>

#include "format.hpp"

class BitcoinExchange {
    private:
        std::map<std::string, float> _rates;

        BitcoinExchange(BitcoinExchange const& copy);
        BitcoinExchange& operator=(BitcoinExchange const& other);

        void  _getDataBase(void);
        void  _extractDataBase(std::ifstream& file);
        void  clearLine(std::string& str);
        void  checkFirstLine(std::string& header, int type);
        void  _verifyLine(std::string& line, std::string& date, float& value, int type);
        float _getValue(std::string& str);
        bool  _verifyDate(std::string& date);
        bool  _verifyDateFormat(std::string& date);
        void  _getDate(std::string& date, int& year, int& month, int& day);
        bool  _verifyYear(int& year);
        bool  _verifyMonth(int& month);
        bool  _verifyDay(int& day, int& month, int& year);
        void  _verifyValueRange(float& value);
        float _getRates(std::string date);

    public:
        BitcoinExchange(void);
        ~BitcoinExchange(void);

        class DataBaseFileNotOpenException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class DataBaseFileEmptyException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class InputFileNotOpenException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class InputFileEmptyException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class InvalidDataBaseException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class InvalidInputException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class BadInputException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class BadDateException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class BadValueException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class UnderValueException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class AboveValueException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class DateNotFoundException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        void start(std::string fileName);
};

#endif