#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    // Initialize contact count to zero
    this->contactCount = 0;
}

PhoneBook::~PhoneBook()
{
}

// Add a new Constact to the PhoneBook
void PhoneBook::addContact()
{
    std::string firstName = getLine("First Name : ");
    std::string lastName = getLine("Last Name : ");
    std::string nickname = getLine("Nickname : ");
    std::string phoneNumber = getLine("Phone Number : ");

    if (isNumber(phoneNumber))
        return;

    std::string darkestSecret = getLine("Darkest Secret : ");

    Contact newContact(
        firstName,
        lastName,
        nickname,
        phoneNumber,
        darkestSecret
    );

    if (contactCount < 8) {
        contacts[contactCount] = newContact;
        contactCount++;
    } else {
        for (int i = 7; i > 0; i--) {
            contacts[i] = contacts[i - 1];
        }
        contacts[0] = newContact;
    }
    if (contactCount < 8)
        contactCount++;
}

//List all the contacts in the Phone Book
void PhoneBook::listContacts()
{
    // Display the header for the contact list
    std::cout << "\n"<< std::setw(10) << "Index";
    std::cout << "|" << std::setw(10) << "First Name";
    std::cout << "|" << std::setw(10) << "Last Name";
    std::cout << "|" << std::setw(10) << "Nickname";
    std::cout << "\n-------------------------------------------\n";

    //List contacts
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

// Display the deatils of a specific contact
void PhoneBook::displayContact()
{
    std::string index = getLine("  > Enter the index of the contact to display : ");
    if (index.length() != 1 || isNumber(index))
    {
        std::cout << "\tInvalid Index "<< std::endl;
        return;
    }
    int idx = std::atoi(index.c_str());
    if (idx < 0 || idx >= this->contactCount)
    {
        std::cout << "\tInvalid Index "<< std::endl;
        return;
    }
    else
    {
        contacts[idx].showInformation();
    }
}


