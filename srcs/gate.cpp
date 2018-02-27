//
// EPITECH PROJECT, 2018
// PSU_2017_malloc
// File description:
// Makefile
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

bool    my_and(bool a, bool b)
{
    return (a && b);
}

bool    my_nand(bool a, bool b)
{
    return (!(a && b));
}

bool    my_or(bool a, bool b)
{
    return (a || b);
}

bool    my_nor(bool a, bool b)
{
    return (!(a || b));
}

bool    my_xor(bool a, bool b)
{
    return (a != b && (a || b));
}

int main(int argc, char **argv)
{
    std::cout << "Je suis dans le main" << std::endl;
    if (argc != 3)
        return (-1);
    std::cout << "Je suis apres le if" << std::endl;
    bool a;
    bool b;
    std::cout << "Je suis ici" << std::endl;
    if (atoi(argv[1]) == 1)
        a = true;
    else if (atoi(argv[1]) == 0)
        a = false;
    std::cout << "Je suis la" << std::endl;
    if (atoi(argv[2]) == 1)
        b = true;
    else if (atoi(argv[2]) == 0)
        b = false;
    std::cout << "Je suis a epitech" << std::endl;
        bool ret = my_xor(a, b);
        if (ret == true)
            std::cout << "TRUE" << std::endl;
        else
            std::cout << "FALSE" << std::endl;

            return (0);
}