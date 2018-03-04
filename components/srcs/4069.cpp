//
// EPITECH PROJECT, 2018
// 4069
// File description:
//
//

#include "../include/4069.hpp"

nts::C4069::C4069(const std::string &name) : _name(name), nb_in(6), nb_out(6)
{
	for (int i = 0; i < 13; i++)
		_pins.push_back(UNDEFINED);
}

nts::Tristate	nts::C4069::compute(std::size_t pin)
{
	_pins[1] = my_inverse(_pins[0]);
	_pins[3] = my_inverse(_pins[2]);
	_pins[5] = my_inverse(_pins[4]);
	_pins[7] = my_inverse(_pins[8]);
	_pins[9] = my_inverse(_pins[10]);
	_pins[11] = my_inverse(_pins[12]);
	return _pins[pin];
}

nts::Tristate		nts::C4069::my_inverse(nts::Tristate state)
{
	if (state == (nts::Tristate)1)
		return ((nts::Tristate)0);
	else if (state == (nts::Tristate)0)
		return ((nts::Tristate)1);
	else
		return ((nts::Tristate)-1);
}


void		nts::C4069::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	_pins[pin] = other.getPinAddr(otherPin);
}

void		nts::C4069::dump() const
{
	int	i = 0;

	while (i < _pins.size())
		std::cout << _name << "[" << i << "]" << "=" << _pins[i++] << std::endl;
}

std::string	nts::C4069::getName() const
{
	return _name;
}

void		nts::C4069::setState(nts::Tristate state, size_t pinNumber)
{
	_pins[pinNumber] = state;
}

nts::Tristate	nts::C4069::getPinAddr(size_t pinNum)
{
	return _pins[pinNum];
}
