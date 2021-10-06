#pragma once
#include <iostream>
class InputException : public std::exception
{
private:
    std::string m_error;
public:
    InputException(std::string error);
    const char* what() const noexcept override;
};

int build_chain(std::string string_input);