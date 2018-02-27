//
//EPITECH PROJECT, 2018
//PSU_2017_malloc
//File description:
//Makefile
//

#ifndef __4008_HPP__
# define __4008_HPP__

#include "IComponent.hpp"

#include <vector>

namespace nts {
	class C4008;
};

class	C4008 : public nts::IComponent
{
	const int	nb_in;
	const int	nb_out;
	
	std::string			_name;
	std::vector<nts::Tristate>	_pins;

public:
	C4008(std::string);
	virtual ~C4008() {};
};


#endif /* __4008_HPP__ */