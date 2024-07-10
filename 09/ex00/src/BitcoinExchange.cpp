#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
    _getDataBase();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& copy)
{
    *this = copy;
}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& other)
{
    if (this != &other)
        *this = other;
    return *this;
}

void BitcoinExchange::_getDataBase(void)
{
    std::ifstream file("data.csv");

    if (!file.is_open())
        throw DataBaseFileNotOpenException();
    file.peek();
    if (file.eof()) {
        file.close();
        throw DataBaseFileEmptyException();
    }
    _extractDataBase(file);
}

void BitcoinExchange::_extractDataBase(std::ifstream& file)
{
    std::string str, line, date;

    std::getline(file, line);
    clearLine(line);
    checkFirstLine(line, 2);
    while (std::getline(file, line)) {
        clearLine(line);
        date = line.substr(0, line.find(','));
        str = line.substr(line.find(',') + 1);
        clearLine(date);
        this->_rates[date] = _getValue(str);
    }
}

void BitcoinExchange::start(std::string fileName)
{
    std::ifstream file(fileName.c_str());
    std::string   line, date;
    float         value;

    if (!file.is_open())
        throw InputFileNotOpenException();
    file.peek();
    if (file.eof()) {
        file.close();
        throw InputFileEmptyException();
    }

    std::getline(file, line);
    clearLine(line);
    checkFirstLine(line, 1);
    while (std::getline(file, line)) {
        try {
            clearLine(line);
            _verifyLine(line, date, value, 1);
            std::cout << GREEN << date << " | " << value;
            std::cout << " = " << value * _getRates(date) << RESET << std::endl;
        }
        catch (std::exception& e) {
            std::cout << RED << e.what() << std::endl << RESET;
            continue;
        }
    }
}

void BitcoinExchange::clearLine(std::string& str)
{
    str.erase(0, str.find_first_not_of(" \t\r\n"));
    str.erase(str.find_last_not_of(" \t\r\n") + 1);
}

void BitcoinExchange::checkFirstLine(std::string& header, int type)
{
    std::istringstream ss(header);
    std::string        date, value;
    std::string        standard = (type == 1) ? "value" : "exchange_rate";
    char               d = (type == 1) ? '|' : ',';

    if (std::getline(ss, date, d) && std::getline(ss, value)) {
        clearLine(date);
        clearLine(value);
        if (!date.length() || !value.length() || date != "date" || value != standard) {
            if (type == 2)
                throw InvalidDataBaseException();
            else
                throw InvalidInputException();
        }
    }
    if (type == 1) {
        std::cout << MAGENTA;
        std::cout << date << std::setw(8) << std::right << d;
        std::cout << std::setw(6) << std::right << value;
        std::cout << RESET << std::endl;
    }
}

void BitcoinExchange::_verifyLine(std::string& line, std::string& date, float& value, int type)
{
    char   d = (type == 1) ? '|' : ',';
    size_t pos = line.find(d);

    if (pos == std::string::npos || pos == 0 || pos == line.length() - 1)
        throw BadInputException();

    date = line.substr(0, pos);
    std::string str = line.substr(pos + 1);
    value = _getValue(str);

    clearLine(date);
    if (!_verifyDate(date))
        throw BadDateException();
    _verifyValueRange(value);
}

float BitcoinExchange::_getValue(std::string& str)
{
    float value;

    clearLine(str);
    for (size_t i = 0; i < str.length(); ++i) {
        if (isalpha(str[i]) && str[i] != '.')
            throw BadValueException();
    }
    std::istringstream iss(str);
    iss >> value;
    return value;
}
bool BitcoinExchange::_verifyDate(std::string& date)
{
    int year, month, day;

    if (!_verifyDateFormat(date))
        return false;
    _getDate(date, year, month, day);
    if (!_verifyYear(year) || !_verifyMonth(month) || !_verifyDay(day, month, year))
        return false;
    return true;
}

bool BitcoinExchange::_verifyDateFormat(std::string& date)
{
    if (date.length() != 10)
        return (false);
    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7) {
            if (date[i] != '-')
                return false;
        }
        else if (!std::isdigit(date[i]))
            return false;
    }
    return true;
}

void BitcoinExchange::_getDate(std::string& date, int& year, int& month, int& day)
{
    std::istringstream iss(date);
    std::string        yearStr, monthStr, dayStr;

    std::getline(iss, yearStr, '-');
    std::getline(iss, monthStr, '-');
    std::getline(iss, dayStr);

    std::istringstream(yearStr) >> year;
    std::istringstream(monthStr) >> month;
    std::istringstream(dayStr) >> day;
}

bool BitcoinExchange::_verifyYear(int& year)
{
    return year >= 1 && year <= 9999;
}

bool BitcoinExchange::_verifyMonth(int& month)
{
    return month >= 1 && month <= 12;
}

bool BitcoinExchange::_verifyDay(int& day, int& month, int& year)
{
    int daysMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        daysMonth[1] = 29;
    return day >= 1 && day <= daysMonth[month - 1];
}

void BitcoinExchange::_verifyValueRange(float& value)
{
    if (value < 0)
        throw UnderValueException();
    if (value > 1000)
        throw AboveValueException();
}

float BitcoinExchange::_getRates(std::string date)
{
    std::map<std::string, float>::iterator it = this->_rates.find(date);

    if (it != this->_rates.end())
        return it->second;

    it = this->_rates.lower_bound(date);
    if (it != this->_rates.begin()) {
        --it;
        return it->second;
    }
    throw DateNotFoundException();
}
// Exceptions =================================================================
const char* BitcoinExchange::DataBaseFileEmptyException::what() const throw()
{
    return "Error: Data base file is empty!";
}

const char* BitcoinExchange::DataBaseFileNotOpenException::what() const throw()
{
    return "Error: Could not opening data base file!";
}

const char* BitcoinExchange::InputFileEmptyException::what() const throw()
{
    return "Error: Input file is empty!";
}

const char* BitcoinExchange::InputFileNotOpenException::what() const throw()
{
    return "Error: Could not opening input file!";
}

const char* BitcoinExchange::InvalidDataBaseException::what() const throw()
{
    return "Error: Data Base file format is invalid!";
}

const char* BitcoinExchange::InvalidInputException::what() const throw()
{
    return "Error: Input file format is invalid!";
}

const char* BitcoinExchange::BadInputException::what() const throw()
{
    return "Error: bad input";
}

const char* BitcoinExchange::BadDateException::what() const throw()
{
    return "Error: invalid date format";
}

const char* BitcoinExchange::BadValueException::what() const throw()
{
    return "Error: invalid value";
}

const char* BitcoinExchange::UnderValueException::what() const throw()
{
    return "Error: not a positive number";
}

const char* BitcoinExchange::AboveValueException::what() const throw()
{
    return "Error: too large a number";
}

const char* BitcoinExchange::DateNotFoundException::what() const throw()
{
    return "Error: date not found";
}