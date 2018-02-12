//
//EPITECH PROJECT, 2018
//PSU_2017_malloc
//File description:
//Makefile
//

#include <iostream>
#include <fstream>
#include "../include/Parser.hpp"

Parser::Parser(int argc, char **argv)
{
	std::ifstream	file;
 	std::string	str;

	file.open(argv[1]);
	if (file.is_open()) 
	{
		while (std::getline(file, str))
			std::cout << str << std::endl;
	}		
	file.close();
	
}

Parser::~Parser()
{

}

bool	Parser::error_manage(int argc, char **argv)
{
	if (argc != 2)
		return (false);
	return (true);
	
}
