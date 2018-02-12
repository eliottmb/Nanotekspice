//
//EPITECH PROJECT, 2018
//PSU_2017_malloc
//File description:
//Makefile
//

#include <iostream>
#include <fstream>

int	main()
{
	std::ifstream	myReadFile;
 	std::string	str;

	myReadFile.open("text.txt");
 	if (myReadFile.is_open()) 
	{
 		while (!myReadFile.eof())
		{
	    		myReadFile >> str;
    			std::cout << str << std::endl;
		}
	}
	myReadFile.close();
	return (0);
}