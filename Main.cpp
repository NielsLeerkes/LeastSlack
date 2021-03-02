/*
 * Main.cpp
 *
 *  Created on: 2 mrt. 2021
 *      Author: na_le
 */

#include <iostream>
#include <fstream>
#include <string>
#include "JobShop.h"
int main(int argc, char **argv)
{
	int x;
	char name[256];
	int counter;
	std::cout << "Enter the file name:";
	std::cin.getline(name, 256);
	std::cout << name << std::endl;

	std::ifstream istrm;
	istrm.open(name);

	JobShop shopA();
	int eolCounter =0;
	while (istrm >> x)
	{
		if (x == '\0')
							{
								std::cout << std::endl;
								++eolCounter;
							}
		if (eolCounter != 0)
		{
			if (counter == 0)
			{
				std::cout << "Machine: ";
				++counter;
			}
			if (counter == 1)
			{
				std::cout << "Duration: ";
				counter = 0;
			}


			std::cout << x << "\t";
		}


	}

	istrm.close();

	return 0;
}
