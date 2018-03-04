//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// simulate chipsets
//

#include <functional>
#include <iostream>
#include "../include/IComponent.hpp"
#include "../include/AComponent.hpp"

int	main()
{
	nts::AComponent	test;

	test.createComponent("input", "a1");
	std::cout << "test\n";
}
