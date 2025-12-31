#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

Contact::Contact(
    std::string firstName,
    std::string lastName,
    std::string nickname,
    std::string phoneNumber,
    std::string darkestSecret)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->nickname = nickname;
    this->phoneNumber = phoneNumber;
    this->darkestSecret = darkestSecret;
}

std::string  truncatText(std::string text)
{
    return (text.length() > 10)
        ? (text.substr(0, 9) + '.')
        : (text);
}

std::string Contact::getFirstName()
{
    return truncatText(this->firstName);
}

std::string Contact::getLastName()
{
    return truncatText(this->lastName);
}

std::string Contact::getNickname()
{
    return truncatText(this->nickname);
}

std::string Contact::getPhoneNumber()
{
    return this->phoneNumber;
}

std::string Contact::getDarkestSecret()
{
    return this->darkestSecret;
}

void Contact::showInformation()
{
    std::cout << "  ==========\n  informations  \n  =========="<< std::endl;
    std::cout << "  First Name: " << this->firstName << std::endl;
    std::cout << "  Last Name: " << this->lastName << std::endl;
    std::cout << "  Nickname: " << this->nickname << std::endl;
    std::cout << "  Phone Number: " << this->phoneNumber << std::endl;
    std::cout << "  Darkest Secret: " <<  this->darkestSecret << std::endl;
}

