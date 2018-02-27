//
//EPITECH PROJECT, 2018
//PSU_2017_malloc
//File description:
//Makefile
//

#ifndef __4094_HPP__
# define __4094_HPP__

#include "IComponent.hpp"

#include <vector>

namespace nts {
	class C4094;
};

class	C4094 : public nts::IComponent
{
	const int	nb_in;
	const int	nb_out;
	
	std::string			_name;
	std::vector<nts::Tristate>	_pins;

public:
	C4094(std::string);
	virtual ~C4094() {};
};


#endif /* __4094_HPP__ */