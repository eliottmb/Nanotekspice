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
    this->_douille.open("de_batard.txt");
    if (!this->_file.is_open() || !this->_douille.is_open()) 
		exit(84);
}

ErrorManage::~ErrorManage()
{

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
	std::size_t	found;

	while (std::getline(this->_file, this->_str))
	{	
		found = this->_str.find('\t');
		//std::cout << found << std::endl;
		while (found!= std::string::npos)
		{
			std::cout << this->_str << std::endl;
			this->_str.replace(found, 1, " ");
		}
        	std::cout << this->_str << std::endl;
	}
	this->back_in();
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
	if (std::remove(to_c_star(this->_path)) != 0)
		return (false);
	if (std::rename(to_c_star("de_batard.txt"), to_c_star(this->_path)) != 0)
		return (false);
	this->_file.open(to_c_star(this->_path));
    	if (!this->_file.is_open()) 
		return (false);	
	return (true);
}

// check file 
//	// check ligne vide->delete line
// check tab = space
// check multispace = space
// check there is a name 
// check only one name
// check nombre de pin relie a chaque fois 
// check si c'est bien un composant du sujet
// check si le nombre de pin est bon
//