//
// EPITECH PROJECT, 2018
// 4081
// File description:
//
//

#include "../include/4081.hpp"

nts::C4081::C4081(const std::string &name) : _name(name), nb_in(8), nb_out(4)
{
	for (int i = 0; i < 14; i++)
		_pins.push_back(UNDEFINED);
}

nts::Tristate	nts::C4081::compute(std::size_t pin)
{
	_pins[2] = my_and(_pins[0], _pins[1]);
	_pins[3] = my_and(_pins[4], _pins[5]);
	_pins[9] = my_and(_pins[7], _pins[8]);
	_pins[10] = my_and(_pins[11], _pins[12]);
	return nts::TRUE;
}

void		nts::C4081::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	_pins[pin] = other.getPinAddr(otherPin);
}

void		nts::C4081::dump() const
{
	int	i = 0;

	while (i < _pins.size()) {
		std::cout << _name << "[" << i << "]" << "=";
		if (_pins[i] == nts::UNDEFINED)
			std::cout << "U\n";
		else
			std::cout << _pins[i] << std::endl;
		i++;
	}
}

std::string	nts::C4081::getName() const
{
	return _name;
}

void		nts::C4081::setState(nts::Tristate state, size_t pinNumber)
{
	_pins[pinNumber] = state;
}

nts::Tristate	nts::C4081::getPinAddr(size_t pinNum)
{
	return _pins[pinNum];
}
