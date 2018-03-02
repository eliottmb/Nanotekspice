//
//EPITECH PROJECT, 2018
//PSU_2017_malloc
//File description:
//Makefile
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
	if (this->check_for_names() == false/* || check_for_struct() == false*/)
		return (false);
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

/*bool		ErrorManage::check_for_struct()
{
	while (std::getline(this->_file, this->_str))
		{
			if ((this->_str.find(".chipsets:") == std::string::npos) && this->_str.size() == 10)
				|| (this->_str.find(".links:") == std::string::npos) && this->_str.size() == 7)
				|| (this->_str.find("input "))
				&& this->_str.find("input ") == std::string::npos
				&& this->_str.find("output ") == std::string::npos
				&& this->_str.find(".links") == std::string::npos
				this->_str.find("") == std::string::npos
		}
	this->back_in();
	this->check_for_tab();
	return (true);
*/

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

// check file 
//	// check ligne vide->delete line
// check tab = space
// check multispace = space
// check there is a name 
// check only one name
// check si c'est bien un composant du sujet

// check nombre de pin relie a chaque fois 
// check si le nombre de pin est bon
// check names for links
// 
