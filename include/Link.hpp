//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// simulate chipsets
//

#ifndef __LINK_HPP__
# define __LINK_HPP__

#include <string>

struct	Link
{
    std::string     _comp;
    std::string     _pin;
    std::string     _comp1;
    std::string     _pin1;

    Link(std::string c, std::string p, std::string c1, std::string p1);
    Link();
    ~Link();
};

#endif /* __LINK_HPP__ */