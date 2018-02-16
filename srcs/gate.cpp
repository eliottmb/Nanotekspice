//
//EPITECH PROJECT, 2018
//PSU_2017_malloc
//File description:
//Makefile
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
    if (argc != 3)
        return (-1);

    bool a;
    bool b;
    if (atoi(argv[1]) == 1)
        a = true;
    else if (atoi(argv[1]) == 0)
        a = false;
    if (atoi(argv[2]) == 1)
        b = true;
    else if (atoi(argv[2]) == 0)
        b = false;

        bool ret = my_xor(a, b);
        if (ret == true)
            std::cout << "TRUE" << std::endl;
        else
            std::cout << "FALSE" << std::endl;

            return (0);
}