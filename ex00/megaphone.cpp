#include <iostream>
#include <iterator>

int main(int ac, char **av)
{
    if (ac <= 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return (0);
    }
    int i;
    for (i = 1 ; i < ac; i++)
    {
        for (int j = 0; av[i][j]; j++)
            if (av[i][j] >= 'a' && av[i][j] <= 'z')
                std::cout << (char)std::toupper(av[i][j]);
            else
                std::cout << av[i][j];
    }
    std::cout << std::endl;
    return (0);
}

