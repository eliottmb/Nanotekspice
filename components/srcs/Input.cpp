//
// EPITECH PROJECT, 2018
// input
// File description:
//
//

#include "../include/Input.hpp"

nts::Input::Input(const std::string &name) : _name(name)
{
	_pin.push_back(FALSE);
}

nts::Tristate	nts::Input::compute(std::size_t pin)
{
	return _pin[0];
}

void	nts::Input::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	std::cout << "setLink\n";
}

void	nts::Input::dump() const
{
	std::cout << "dump\n";
}

std::string	nts::Input::getName() const
{
	return _name;
}

void		nts::Input::setState(nts::Tristate state, size_t pinNumber)
{
	_pin[pinNumber] = state;
}
