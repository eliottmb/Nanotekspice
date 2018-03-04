//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// simulate chipsets
//
#include <stdlib.h>
#include <iostream>
#include <string>
#include "../include/ErrorManage.hpp"

ErrorManage::ErrorManage(std::string path)
{
	this->_my_comps = Components();
	this->_path = path;
	this->_file.open(this->_path.c_str());
	this->_douille.open(std::string("tmp_file.txt").c_str());
	if (!this->_file.is_open() || !this->_douille.is_open())
		exit(84);
	this->do_all_checks();
}

ErrorManage::~ErrorManage()
{
	this->_file.close();
	this->_douille.close();
}

bool	ErrorManage::do_all_checks()
{
	this->check_for_coms();
	this->check_for_empty_line();
	this->check_for_tabs();
	this->check_for_useless_space();
	if (this->check_for_names() == false)
		return (false);
	/*if (check_for_struct() == false)
		return (false);*/
	return (true);
}

void	ErrorManage::check_for_coms()
{
	unsigned long	found;

	while (std::getline(this->_file, this->_str))
	{	
		found = this->_str.find("#");
			if (found == std::string::npos)
				this->_douille << this->_str << std::endl;
	}
	this->back_in();
}

void    ErrorManage::check_for_empty_line()
{
	while (std::getline(this->_file, this->_str))
		{
			if (this->_str != "")
                	this->_douille << this->_str << std::endl;
		}
	this->back_in();
}

void    ErrorManage::check_for_tabs()
{
	int		found;
	
	while (std::getline(this->_file, this->_str))
	{	
		do
		{
			found = this->_str.find('\t');
			if (found != -1)
				this->_str.replace(found, 1, " ");
			} while (found != -1);
		this->_douille << this->_str << std::endl;
	}
	this->back_in();
}

void	ErrorManage::check_for_useless_space()
{
	unsigned long		found;

	while (std::getline(this->_file, this->_str))
	{	
		do
		{
			while (this->_str.c_str()[0] == ' ')
				this->_str.replace(0, 1, "");
			found = this->_str.find("  ");
			if (found != std::string::npos)
				this->_str.replace(found, 2, " ");
			} while (found != std::string::npos);
		if (this->_str.c_str()[this->_str.size() - 1] == ' ')
			this->_str = this->_str.substr(0, this->_str.size() - 1);
		this->_douille << this->_str << std::endl;
	}
	this->back_in();
	std::remove(std::string("tmp_file.txt").c_str());
}

bool		ErrorManage::check_for_names()
{
	int		i;
	
	while (std::getline(this->_file, this->_str))
	{	
		i = this->_my_comps.find_in_component_tab(this->_str);
		if (i != -1)
			return (true);
	}
	return (false);
}

bool		ErrorManage::check_for_struct()
{
	std::cout << "We are in check_for_struct" << std::endl;
	while (std::getline(this->_file, this->_str))
		{
			std::cout << this->_str << this->_str.size() << std::endl;
			std::cout << "before if" << std::endl;
			if (this->_str.find(".chipsets:") != std::string::npos && this->_str.size() == 10)
				std::cout << "lala" << std::endl;
			if (this->_str.find(".links:") != std::string::npos && this->_str.size() == 7)
				std::cout << "lele" << std::endl;
			if (this->_str.find("input ") != std::string::npos && this->_str.size() >= 7)
				std::cout << "lili" << std::endl;
			if (this->_str.find("output ") != std::string::npos && this->_str.size() >= 8)
				std::cout << "lolo" << std::endl;
			if (this->_my_comps.find_in_component_tab(this->_str) != -1 && this->_str.size() == 5)
				std::cout << "lulu" << std::endl;				
			else if (check_for_links(this->_str) == true)
				return (true);
		}
	return (false);
}

bool		ErrorManage::check_for_links(std::string to_test)
{
	std::cout << "We are in check for links:" << to_test << std::endl;
	unsigned long	i;
	unsigned long	j;

	i = to_test.find(":");
	j = to_test.find(" ");
	if (i == std::string::npos || j == std::string::npos || i >= j)
		return (false);
	to_test = to_test.substr(j + 1, to_test.size());
	std::cout << to_test << std::endl;
	return (true);
}

bool		ErrorManage::back_in()
{
	int	i;

	this->_file.close();
	this->_douille.close();
	if (std::remove(this->_path.c_str()) != 0)
	{
		std::cout << "ERROR 0" << std::endl;
		return (false);
	}
	i = std::rename(std::string("tmp_file.txt").c_str(), this->_path.c_str());
	if (i != 0)
	{
		std::cout << "ERROR 1" << i <<std::endl;
		std::perror("rename");
		return (false);
	}
	this->_file.open(this->_path.c_str());
    	this->_douille.open(std::string("tmp_file.txt").c_str());
    	if (!this->_file.is_open() || !this->_douille.is_open())
		exit(84);
	return (true);
}
