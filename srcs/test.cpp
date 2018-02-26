//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include <functional>
#include <iostream>
#include "../include/IComponent.hpp"
#include "../include/AComponent.hpp"

int	main()
{
	nts::AComponent	test;

	test.createComponent("input", "a1");
	test.createComponent("output", "s1");
	std::cout << "test\n";

}
