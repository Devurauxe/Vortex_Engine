#include "error_handler.h"

#include <iostream>
#include <cstdlib>

void fatalError(std::string errorString)
{
	std::cout << errorString << std::endl;
	std::cout << "Enter any key to quit...";
	int tmp;
	std::cin >> tmp;
	exit(1);
}