#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    loadDataBase();
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _rates(other._rates) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other) {
        _rates = other._rates;
    }
    return *this;
}

void BitcoinExchange::loadDataBase()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
        throw std::runtime_error("could not open file.");
    processDataBase(file);
}

void BitcoinExchange::processDataBase(std::ifstream& file)
{
    std::string line;
    std::getline(file, line);
    checkHeader(line, 2);

    while (std::getline(file, line)) {
        trim(line);
        std::istringstream iss(line);
        std::string        date, value;
        if (std::getline(iss, date, ',') && std::getline(iss, value)) {
            trim(date);
            float rate;
            if (isValidValue(value, rate)) {
                _rates[date] = rate;
            }
        }
    }
}

void BitcoinExchange::checkHeader(const std::string& header, int type)
{
    std::istringstream ss(header);
    std::string        date, value;
    char               delimiter = (type == 1) ? '|' : ',';
    std::string        expectedValue = (type == 1) ? "value" : "exchange_rate";

    if (std::getline(ss, date, delimiter) && std::getline(ss, value)) {
        trim(date);
        trim(value);
        if (date != "date" || value != expectedValue) {
            throw std::runtime_error("Invalid header format.");
        }
    }
}

void BitcoinExchange::trim(std::string& str)
{
    str.erase(0, str.find_first_not_of(" \t\n\r"));
    str.erase(str.find_last_not_of(" \t\n\r") + 1);
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
    if (date.length() != 10)
        return false;

    for (size_t i = 0; i < date.length(); ++i) {
        if ((i == 4 || i == 7) && date[i] != '-')
            return false;
        if (i != 4 && i != 7 && !isdigit(date[i]))
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2) {
        bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (isLeapYear) {
            daysInMonth[1] = 29;
        }
    }

    if (day > daysInMonth[month - 1])
        return false;

    return true;
}

bool BitcoinExchange::isValidValue(const std::string& str, float& value)
{
    std::istringstream iss(str);
    iss >> value;
    if (iss.fail() || !iss.eof())
        return false;
    return true;
}

float BitcoinExchange::getRate(const std::string& date)
{
    std::map<std::string, float>::iterator it = _rates.find(date);
    if (it != _rates.end())
        return it->second;

    it = _rates.lower_bound(date);
    if (it != _rates.begin()) {
        --it;
        return it->second;
    }
    throw std::runtime_error("date not found in database.");
}

void BitcoinExchange::start(const std::string& fileName)
{
    std::ifstream file(fileName.c_str());
    if (!file.is_open())
        throw std::runtime_error("could not open file.");
    if (file.peek() == std::ifstream::traits_type::eof())
        throw std::runtime_error("file is empty.");

    std::string line;
    std::getline(file, line);
    checkHeader(line, 1);

    while (std::getline(file, line)) {
        try {
            trim(line);
            std::istringstream iss(line);
            std::string        date, value;
            if (std::getline(iss, date, '|') && std::getline(iss, value)) {
                trim(date);
                float amount;
                if (isValidDate(date)) {
                    if (isValidValue(value, amount)) {
                        if (amount < 0) {
                            std::cerr << "Error: not a positive number." << std::endl;
                        }
                        else if (amount > 1000) {
                            std::cerr << "Error: too large a number." << std::endl;
                        }
                        else {
                            float rate = getRate(date);
                            std::cout << date << " => " << amount << " = " << amount * rate
                                      << std::endl;
                        }
                    }
                    else {
                        std::cerr << "Error: bad input => " << line << std::endl;
                    }
                }
                else {
                    std::cerr << "Error: bad input => " << line << std::endl;
                }
            }
            else {
                std::cerr << "Error: bad input => " << line << std::endl;
            }
        }
        catch (const std::runtime_error& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
}
