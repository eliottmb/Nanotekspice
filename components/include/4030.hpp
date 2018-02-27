//
//EPITECH PROJECT, 2018
//PSU_2017_malloc
//File description:
//Makefile
//

#ifndef __4030_HPP__
# define __4030_HPP__

#include "IComponent.hpp"

#include <vector>

namespace nts {
	class C4030;
};

class	C4030 : public nts::IComponent
{
	const int	nb_in;
	const int	nb_out;
	
	std::string			_name;
	std::vector<nts::Tristate>	_pins;

public:
	C4030(std::string);
	virtual ~C4030() {};
};


#endif /* __4030_HPP__ */