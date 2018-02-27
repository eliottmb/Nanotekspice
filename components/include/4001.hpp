//
//EPITECH PROJECT, 2018
//PSU_2017_malloc
//File description:
//Makefile
//

#ifndef __4001_HPP__
# define __4001_HPP__

#include "IComponent.hpp"

#include <vector>

namespace nts {
	class C4001;
};

class	C4001 : public nts::IComponent
{
	const int	nb_in;
	const int	nb_out;
	
	std::string			_name;
	std::vector<nts::Tristate>	_pins;

public:
	C4001(std::string);
	virtual ~C4001() {};
};


#endif /* __4001_HPP__ */