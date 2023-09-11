#pragma once
#include <string>
#include <iostream>
#include <exception>

class OutOfRangeException : public std::exception {
private:
    std::string message;
public:
    OutOfRangeException(const std::string& error) : message(error) {};
    const char* what() const noexcept override;
};

class IncompatibleDimException : public std::exception {
private:
    std::string message;
public:
    IncompatibleDimException(const std::string& error) : message(error) {};
    const char* what() const noexcept override;
};