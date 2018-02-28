//
// EPITECH PROJECT, 2018
// PSU_2017_malloc
// File description:
// Makefile
//

#include "gate.hpp"
#include "IComponent.hpp"

nts::Tristate    my_and(nts::Tristate a, nts::Tristate b)
{
	if (a == 1 && b == 1)
		return nts::TRUE;
	return nts::FALSE;
}

nts::Tristate    my_nand(nts::Tristate a, nts::Tristate b)
{
	return nts::TRUE;
	//return (!(a && b));
}

nts::Tristate    my_or(nts::Tristate a, nts::Tristate b)
{
	return nts::TRUE;
	//return (a || b);
}

nts::Tristate    my_nor(nts::Tristate a, nts::Tristate b)
{
	return nts::TRUE;
	//return (!(a || b));
}

nts::Tristate    my_xor(nts::Tristate a, nts::Tristate b)
{
	return nts::TRUE;
	//return (a != b && (a || b));
}
