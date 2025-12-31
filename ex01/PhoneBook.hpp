#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>
#include <stdlib.h>

class PhoneBook
{
private:
    Contact contacts[8];
    int contactCount;

public:
    PhoneBook();
    ~PhoneBook();

    void addContact();
    void listContacts();
    void displayContact();
};

std::string getLine(std::string prompt);
int isNumber(std::string phoneNumber);
#endif