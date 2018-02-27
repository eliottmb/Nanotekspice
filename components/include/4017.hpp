//
//EPITECH PROJECT, 2018
//PSU_2017_malloc
//File description:
//Makefile
//

#ifndef __4017_HPP__
# define __4017_HPP__

#include "IComponent.hpp"

#include <vector>

namespace nts {
	class C4017;
};

class	C4017 : public nts::IComponent
{
	const int	nb_in;
	const int	nb_out;
	
	std::string			_name;
	std::vector<nts::Tristate>	_pins;

public:
	C4017(std::string);
	virtual ~C4017() {};
};


#endif /* __4017_HPP__ */