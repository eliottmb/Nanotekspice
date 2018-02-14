//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include <iostream>
#include "IComponent.hpp"
#include "AComponent.hpp"

int	main()
{
	nts::AComponent	test;

	test.createComponent("input", "a1");
	test.createComponent("output", "s1");
	std::cout << "test\n";

}
