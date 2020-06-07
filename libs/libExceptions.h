#include <iostream>
#include <exception>
#include <string>
namespace MyRuntimeExceptions {
    class TableErrors : public std::runtime_error {
    public:
        TableErrors() : runtime_error("Wrong character in array") {  };
        TableErrors(std::string msg) : runtime_error(msg.c_str()) {};
    };
}
/**
 * Checks if char array has only letters and frequency array only numbers
 * @param size of the arrays, array of letters, array of frequencies
 * */
