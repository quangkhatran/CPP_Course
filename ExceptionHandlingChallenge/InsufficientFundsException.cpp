#include "InsufficientFundsException.h"

const char* InsufficientFundsException::what() const noexcept {
    return "Insufficient Fund";
}

