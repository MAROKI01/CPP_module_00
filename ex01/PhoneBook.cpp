#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->contactCount = 0;
}

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

int checkPhoneNumber(std::string phoneNumber)
{
    for (size_t i = 0; i < phoneNumber.length(); i++)
    {
        if (!isdigit(phoneNumber[i]))
        {
            std::cout << "Invalid phone number. Please enter digits only." << std::endl;
            return(1);
        }
    }
    return(0);
}

void PhoneBook::addContact()
{
    std::string firstName = getLine("First Name : ");
    std::string lastName = getLine("Last Name : ");
    std::string nickname = getLine("Nickname : ");
    std::string phoneNumber = getLine("Phone Number : ");

    if (checkPhoneNumber(phoneNumber))
        return;

    std::string darkestSecret = getLine("Darkest Secret : ");

    if (contactCount >= 8)
        contactCount = 0;
    contacts[contactCount] = Contact(
        firstName,
        lastName,
        nickname,
        phoneNumber,
        darkestSecret
    );
    contactCount++;
}

void header()
{
    std::cout << std::setw(10) << "Index";
    std::cout << "|" << std::setw(10) << "First Name";
    std::cout << "|" << std::setw(10) << "Last Name";
    std::cout << "|" << std::setw(10) << "Nickname";
    std::cout << "\n-------------------------------------------\n";
}

void PhoneBook::listContacts()
{
    header();

    for (int i = 0; i < this->contactCount; i++)
    {
        std::cout << std::setw(10) << i;
        std::cout << "|" << std::setw(10) << contacts[i].getFirstName();
        std::cout << "|" << std::setw(10) << contacts[i].getLastName();
        std::cout << "|" << std::setw(10) << contacts[i].getNickname() << std::endl;
    }
    std::cout << "\n";

    displayContact();
}

void PhoneBook::displayContact()
{
    std::string index = getLine("  > Enter the index of the contact to display : ");
    int idx = atoi(index.c_str());
    if (idx < 0 || idx >= this->contactCount)
    {
        std::cout << "\tIndex must be between 0 and " << this->contactCount - 1 << std::endl;
        return;
    }
    else
    {
        contacts[idx].showInformation();
    }
}

PhoneBook::~PhoneBook()
{
}
