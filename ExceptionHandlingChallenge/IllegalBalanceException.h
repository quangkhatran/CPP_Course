#ifndef _ILLEGAL_BALANCE_EXCEPTION_H
#define _ILLEGAL_BALANCE_EXCEPTION_H
#include <exception>

class IllegalBalanceException:public std::exception
{
public:
    IllegalBalanceException() noexcept = default;
    ~IllegalBalanceException() = default;
    virtual const char* what() const noexcept override;

};

#endif // _ILLEGAL_BALANCE_EXCEPTION_H
