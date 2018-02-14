//
//EPITECH PROJECT, 2018
//PSU_2017_malloc
//File description:
//Makefile
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include "../include/Parser.hpp"

Parser::Parser(int argc, char **argv)
{
	if (!this->error_manage(argc, argv))
		exit (84);
	this->_state = 0;
	this->_file.open(argv[1]);

	if (!this->_file.is_open()) 
		exit(84);
	while (std::getline(this->_file, this->_str))
		{
			if (find_match() == 0)
			  	this->set_state();
			if (this->get_state() == 1 && find_match() == 1)
				_in.push_back(_str);
			else if (this->get_state() == 1 && find_match() == 2)
				_out.push_back(_str);
		}
	_file.close();
	
}

Parser::~Parser()
{

}

void	Parser::set_state()
{
	this->_state = this->_state + 1;

	if (this->_state >= 2)
		{
			std::cout << "Is there a trouble in here" << std::endl;\
			this->_state = 2;
		}
}

int	Parser::get_state()
{
	return (this->_state);
}

void	Parser::show_vector()
{
	unsigned long	i = 0;

	std::cout << "Voici le vecteur in:" << std::endl;
	while (i < _in.size())
		{
			std::cout << this->_in[i] << std::endl;
			i = i + 1;
		}
	i = 0;
	std::cout << "\nVoici le vecteur out:" << std::endl;
	while (i < _out.size())
		{
			std::cout << this->_out[i] << std::endl;
			i = i + 1;
		}	
}

int	Parser::find_match()
{
	if (_str.find(".chipsets") != std::string::npos)
		return (0);
	if (_str.find("input")  != std::string::npos)
		return (1);
	if (_str.find("output") != std::string::npos)
		return (2);
	return (-1);
}

void	Parser::clean_tab()
{
	int	i = 0;

	while (i < _in.size())
	{
		_in[i].erase(_in[i].begin(), _in[i].begin() + 6);
		i = i + 1;
	}
	i = 0;
	while (i < _out.size())
	{
		_out[i].erase(_out[i].begin(), _out[i].begin() + 7);
		i = i + 1;
	}
}

bool	Parser::error_manage(int argc, char **argv)
{
	if (argc != 2)
		return (false);
	return (true);
}