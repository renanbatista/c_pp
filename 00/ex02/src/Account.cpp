#include "Account.hpp"
#include <cstdarg>
#include <ctime>
#include <iomanip>
#include <iostream>

void
log(int count, ...)
{
    va_list args;
    va_start(args, count);
    for (; count > 1; count -= 2)
    {
        const char* str   = va_arg(args, const char*);
        int         value = va_arg(args, int);
        std::cout << str << ":" << value;
        if (count > 2)
            std::cout << ";";
    }
    if (count == 1)
    {
        const char* str = va_arg(args, const char*);
        std::cout << str;
    }
    std::cout << std::endl;
    va_end(args);
}

int Account::_nbAccounts         = 0;
int Account::_totalAmount        = 0;
int Account::_totalNbDeposits    = 0;
int Account::_totalNbWithdrawals = 0;

int
Account::getNbAccounts()
{
    return _nbAccounts;
}
int
Account::getTotalAmount()
{
    return _totalAmount;
}
int
Account::getNbDeposits()
{
    return _totalNbDeposits;
}
int
Account::getNbWithdrawals()
{
    return _totalNbWithdrawals;
}
int
Account::checkAmount() const
{
    return _amount;
}

void
Account::_displayTimestamp(void)
{
    std::time_t now = std::time(NULL);
    std::tm*    ptm = std::localtime(&now);

    char buffer[20];
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", ptm);
    std::cout << buffer;
}

void
Account::displayAccountsInfos()
{
    _displayTimestamp();
    log(8,
        "accounts",
        _nbAccounts,
        "total",
        _totalAmount,
        "deposits",
        _totalNbDeposits,
        "withdrawals",
        _totalNbWithdrawals);
}

void
Account::displayStatus() const
{
    _displayTimestamp();
    log(8,
        "index",
        _accountIndex,
        "amount",
        _amount,
        "deposits",
        _nbDeposits,
        "withdrawals",
        _nbWithdrawals);
}

void
Account::makeDeposit(int deposit)
{
    _nbDeposits++;
    _totalNbDeposits++;
    _amount += deposit;
    _totalAmount += deposit;
    _displayTimestamp();
    log(10,
        "index",
        _accountIndex,
        "p_amount",
        _amount - deposit,
        "deposit",
        deposit,
        "amount",
        _amount,
        "nb_deposits",
        _nbDeposits);
}

bool
Account::makeWithdrawal(int withdrawal)
{
    if (withdrawal > _amount)
    {
        _displayTimestamp();
        log(5, "index", _accountIndex, "p_amount", _amount, "withdrawal:refused");
        return false;
    }
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    _totalAmount -= withdrawal;
    _amount -= withdrawal;
    _displayTimestamp();
    log(8,
        "index",
        _accountIndex,
        "p_amount",
        _amount + withdrawal,
        "withdrawal",
        withdrawal,
        "amount",
        _amount,
        "nb_withdrawals",
        _nbWithdrawals);
    return true;
}

Account::Account(int initial_deposit)
  : _accountIndex(_nbAccounts)
  , _amount(initial_deposit)
  , _nbDeposits(0)
  , _nbWithdrawals(0)
{
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    log(5, "index", _accountIndex, "amount", _amount, "created");
}

Account::~Account()
{
    _displayTimestamp();
    log(5, "index", _accountIndex, "amount", _amount, "closed");
}
