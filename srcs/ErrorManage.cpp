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
	this->_path = path;
    this->_file.open(to_c_star(this->_path));
    this->_douille.open(to_c_star("de_batard.txt"));
    if (!this->_file.is_open() || !this->_douille.is_open()) 
		exit(84);
	this->init_component_tab();
}

ErrorManage::~ErrorManage()
{

}

void	ErrorManage::init_component_tab()
{
	this->_my_components.push_back("4001");
	this->_my_components.push_back("4008");
	this->_my_components.push_back("4011");
	this->_my_components.push_back("4013");
	this->_my_components.push_back("4017");
	this->_my_components.push_back("4030");
	this->_my_components.push_back("4069");
	this->_my_components.push_back("4071");
	this->_my_components.push_back("4094");
	this->_my_components.push_back("4514");
}

int		ErrorManage::find_in_component_tab()
{
	int	i = 0;
	int	tmp;

	while (i < 10)
	{
		tmp = this->_str.compare(0, 4, this->_my_components[i]);
		if (tmp == 0)
			return (i);
		i = i + 1;
	}
	return (-1);
}

int		ErrorManage::my_find(std::string from, char c)
{
	const char	*str = from.c_str();
	int			i = 0;

	while (str[i])
		{
			if (str[i] == c)
				return (i);
			i = i + 1;
		}
	return (-1);
}

bool    ErrorManage::check_for_empty_line()
{
	while (std::getline(this->_file, this->_str))
		{
			if (this->_str != "")
                	this->_douille << this->_str << std::endl;
		}
		this->back_in();
		return (true);
}

bool    ErrorManage::check_for_tab()
{
	int		found;
	
	while (std::getline(this->_file, this->_str))
	{	
		do
		{
			found = this->my_find(this->_str, 9);
			if (found != -1)
				this->_str.replace(found, 1, " ");
			} while (found != -1);
		this->_douille << this->_str << std::endl;
	}
	this->back_in();
	return (true);
}

bool	ErrorManage::check_for_useless_space()
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
		this->_douille << this->_str << std::endl;
	}
	this->back_in();
	return (true);
}

bool		ErrorManage::check_for_name()
{
	int		i;
	int		j = 0;

	while (std::getline(this->_file, this->_str))
	{	
		i = this->find_in_component_tab();
		if (i != -1)
			{
				if (this->_str.c_str()[4] != ' ' || j != 0)
					return (false);
				this->_name = this->_str.substr(5);
				this->_compo = std::string(this->_my_components[i]);
				if (this->_name.find(' ') != std::string::npos)
					return (false);
				std::cout << "Component: " << this->_my_components[i] << " Name : " << this->_name<< std::endl;
				j = j + 1;
			}
			if (j > 1)
				return (false);
	}
	return (true);
}

const char *ErrorManage::to_c_star(std::string str)
{
	char * writable = new char[str.size() + 1];
	
	std::copy(str.begin(), str.end(), writable);
	writable[str.size()] = '\0';
	return (writable);
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
		i = std::rename(to_c_star("de_batard.txt"), this->_path.c_str());
		if (i != 0)
		{
			std::cout << "ERROR 1" << i <<std::endl;	
			std::perror("rename");
			return (false);
		}
		this->_file.open(to_c_star(this->_path));
    	this->_douille.open(to_c_star("de_batard.txt"));
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
