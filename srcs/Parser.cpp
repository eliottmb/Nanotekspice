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
#include "../include/ErrorManage.hpp"

Parser::Parser(int argc, char **argv, ErrorManage *err)
{
	this->_state = 0;
	this->_err = err;
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
	this->clean_tab();
	this->get_pair_vector();
}

Parser::~Parser()
{
	_file.close();
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

void	Parser::show_pair()
{
	unsigned long	i = 0;

	while (i < _comps.size())
		{
			std::cout << this->_comps[i].first << ": " << this->_comps[i].second << std::endl;
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
	unsigned long	i = 0;

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

std::vector<std::pair<std::string, std::string>	> Parser::get_comps()
{
	return _comps;
}

void			Parser::get_pair_vector()
{
	unsigned long		i = 0;

	while (i < this->_in.size())
	{
		this->_comps.push_back(std::make_pair("input", this->_in[i]));
		i = i + 1;
	}
	i = 0;
	while (i < this->_out.size())
	{
		this->_comps.push_back(std::make_pair("output", this->_out[i]));
		i = i + 1;
	}
	this->_comps.push_back(std::make_pair(this->_err->_compo, this->_err->_name));
}


void			Parser::find_links()
{
	int		i = 0;

	this->_file.open(this->_err->_path.c_str());
    if (!this->_file.is_open())
		exit(84);

	while (std::getline(this->_file, this->_str) && this->_str.find(".links") == std::string::npos)
	;
	while (std::getline(this->_file, this->_str))
	{
		//std::cout << this->_str << std::endl;
		this->fill_map();
		i = i + 1;
	}
}

void	Parser::fill_map()
{
	std::string		tmp;
	std::string		name_comp1;
	unsigned long	pos = this->_str.find(":");

	std::string		name_comp = this->_str.substr(0, pos);
	tmp = this->_str.substr(pos + 1, this->_str.size() - pos - 1);

	pos = tmp.find(" ");
	std::string		nb_pin = tmp.substr(0, pos);
	tmp = tmp.substr(pos + 1, tmp.size() - pos - 1);
	pos = tmp.find(":");

	name_comp1 = tmp.substr(0, pos);
	tmp = tmp.substr(pos + 1, tmp.size() - pos - 1);
	
	std::cout << "name:" << name_comp << "      pin:" << nb_pin << std::endl;
	std::cout << "name:" << name_comp1 << "      pin:" << tmp << std::endl;
	std::cout << "\n\n-----------------------------------------------\n" << std::endl;
	
	this->_my_map.insert(make_pair(name_comp, nb_pin), make_pair(name_comp1, tmp));
}