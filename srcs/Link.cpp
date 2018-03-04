//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// simulate chipsets
//

#include "Link.hpp"

Link::Link(std::string c, std::string p, std::string c1, std::string p1)
    : _comp(c), _pin(p), _comp1(c1), _pin1(p1)
{

}

Link::Link()
{
	_comp = "UNDEFINED";
	_pin = "UNDEFINED";
	_comp1 = "UNDEFINED";
	_pin1 = "UNDEFINED";
}

Link::~Link()
{

}
