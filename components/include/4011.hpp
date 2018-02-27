//
//EPITECH PROJECT, 2018
//PSU_2017_malloc
//File description:
//Makefile
//

#ifndef __4011_HPP__
# define __4011_HPP__

#include "IComponent.hpp"

#include <vector>

namespace nts {
	class C4011;
};

class	C4011 : public nts::IComponent
{
	const int	nb_in;
	const int	nb_out;
	
	std::string			_name;
	std::vector<nts::Tristate>	_pins;

public:
	C4011(std::string);
	virtual ~C4011() {};
};


#endif /* __4011_HPP__ */