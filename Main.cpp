/*
 * Main.cpp
 *
 *  Created on: 1 mrt. 2021
 *      Author: na_le, Camiel Nijman
 *
 */

#include <iostream>
#include <fstream>
#include <string>

#include "JobShop.h"

int main(int argc, char **argv)
{
	int x;
	int machineNr;
	int duration;
	int isDuration = 0;
	char name[256];
	std::cout << "Enter the file name:";
	std::cin.getline(name, 256);
	std::cout << name << std::endl;
	std::ifstream istrm;
	istrm.open(name);



	while (istrm >> x)
	{
		if (isDuration == 1)
		{
			isDuration = 0;
			machineNr = x;
		}
		else
		{

			isDuration = 1;
		}
		std::cout << x << std::endl;
	}

	istrm.close();
	return 0;

}
