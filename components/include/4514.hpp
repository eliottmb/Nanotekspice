//
//EPITECH PROJECT, 2018
//PSU_2017_malloc
//File description:
//Makefile
//

#ifndef __4514_HPP__
# define __4514_HPP__

#include "IComponent.hpp"

#include <vector>

namespace nts {
	class C4514;
};

class	C4514 : public nts::IComponent
{
	const int	nb_in;
	const int	nb_out;
	
	std::string			_name;
	std::vector<nts::Tristate>	_pins;

public:
	C4514(std::string);
	virtual ~C4514() {};
};


#endif /* __4514_HPP__ */