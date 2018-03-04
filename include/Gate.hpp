//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// simulate chipsets
//

#ifndef GATE_H_
# define GATE_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "IComponent.hpp"

nts::Tristate   my_and(nts::Tristate a, nts::Tristate b);
nts::Tristate	my_nand(nts::Tristate a, nts::Tristate b);
nts::Tristate	my_or(nts::Tristate a, nts::Tristate b);
nts::Tristate	my_nor(nts::Tristate a, nts::Tristate b);
nts::Tristate	my_xor(nts::Tristate a, nts::Tristate b);

#endif
