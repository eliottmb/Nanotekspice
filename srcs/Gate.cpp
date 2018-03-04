//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// simulate chipsets
//

#include "Gate.hpp"
//#include "IComponent.hpp"

nts::Tristate    my_and(nts::Tristate a, nts::Tristate b)
{
	if (a == nts::TRUE && b == nts::TRUE)
		return nts::TRUE;
	return nts::FALSE;
	return (nts::Tristate)(a && b);
}

nts::Tristate    my_nand(nts::Tristate a, nts::Tristate b)
{
	return (nts::Tristate)(!(a && b));
}

nts::Tristate    my_or(nts::Tristate a, nts::Tristate b)
{
	return (nts::Tristate)(a || b);
}

nts::Tristate    my_nor(nts::Tristate a, nts::Tristate b)
{
	return (nts::Tristate)(!(a || b));
}

nts::Tristate    my_xor(nts::Tristate a, nts::Tristate b)
{
	return (nts::Tristate)(a != b && (a || b));
}
