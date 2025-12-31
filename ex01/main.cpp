#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook phoneBook;
    std::string input;

    std::cout << "Welcome to the phonebook type\n  ADD | SEARCH | EXIT " << std::endl;

    while(true)
    {
        input = getLine(">> ");
        if (!input.compare("ADD"))
        {
            phoneBook.addContact();
        }
        else if (!input.compare("SEARCH"))
        {
            phoneBook.listContacts();
        }
        else if (!input.compare("EXIT"))
            break;
        else
            std::cout << "NOT INCLUDED TRY : ADD | SEARCH | EXIT" << std::endl;
    }
    return(0);
}
