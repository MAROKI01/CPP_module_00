#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
    if (ac <= 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return (0);
    }
    int i;
    unsigned char c;
    for (i = 1 ; i < ac; i++)
    {
        for (int j = 0; av[i][j]; j++)
        {
            c = (unsigned char)av[i][j];
            std::cout << (char)std::toupper(c);
        }
    }
    std::cout << std::endl;
    return (0);
}

