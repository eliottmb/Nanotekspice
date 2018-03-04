//
// EPITECH PROJECT, 2018
// 4030
// File description:
//
//

#include "../include/4030.hpp"

nts::C4030::C4030(const std::string &name) : _name(name), nb_in(8), nb_out(4)
{
	for (int i = 0; i < 13; i++)
		_pins.push_back(UNDEFINED);
}

nts::Tristate	nts::C4030::compute(std::size_t pin)
{
	_pins[2] = my_xor(_pins[0], _pins[1]);
	_pins[3] = my_xor(_pins[4], _pins[5]);
	_pins[9] = my_xor(_pins[7], _pins[8]);
	_pins[10] = my_xor(_pins[11], _pins[12]);
	return _pins[pin];
}

void		nts::C4030::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	_pins[pin] = other.getPinAddr(otherPin);
}

void		nts::C4030::dump() const
{
	int	i = 0;

	while (i < _pins.size())
		std::cout << _name << "[" << i << "]" << "=" << _pins[i++] << std::endl;
}

std::string	nts::C4030::getName() const
{
	return _name;
}

void		nts::C4030::setState(nts::Tristate state, size_t pinNumber)
{
	_pins[pinNumber] = state;
}

nts::Tristate	nts::C4030::getPinAddr(size_t pinNum)
{
	return _pins[pinNum];
}
