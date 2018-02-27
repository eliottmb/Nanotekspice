//
//EPITECH PROJECT, 2018
//PSU_2017_malloc
//File description:
//Makefile
//

#ifndef __4071_HPP__
# define __4071_HPP__

#include "IComponent.hpp"

#include <vector>

namespace nts {
	class C4071;
};

class	C4071 : public nts::IComponent
{
	const int	nb_in;
	const int	nb_out;
	
	std::string			_name;
	std::vector<nts::Tristate>	_pins;

public:
	C4071(std::string);
	virtual ~C4071() {};
};


#endif /* __4071_HPP__ */