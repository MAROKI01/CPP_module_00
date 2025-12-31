#include "PhoneBook.hpp"

// Get a line from the user 
std::string getLine(std::string prompt)
{
    std::string input;

    for (;;)
    {
        std::cout << prompt;
        if (!std::getline(std::cin, input))
        { std::cout << std::endl; std::exit(0); }

        if (input.empty())
            continue;

        size_t i = 0;
        while (i < input.size() && std::isprint((unsigned char)input[i]))
            ++i;
        if (i == input.size())         
            return input;
    }
}

// Check if the phone number is valid
int isNumber(std::string phoneNumber)
{
    for (size_t i = 0; i < phoneNumber.length(); i++)
    {
        if (!isdigit(phoneNumber[i]))
        {
            std::cout << "Invalid number. Please enter digits only." << std::endl;
            return(1);
        }
    }
    return(0);
}