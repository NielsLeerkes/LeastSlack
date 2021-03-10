/*
 * Main.cpp
 *
 *  Created on: 2 mrt. 2021
 *      Author: na_le
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "JobShop.h"
#include "Job.h"
#include "Task.h"

int main(int argc, char **argv)
{
	signed int eolCounter = 0;
	int amountOfJob = 0;
	int amountOfMachines = 0;
	int counterForParse = 0;
	char name[256];

	std::cout << "Enter the file name:";
	std::cin.getline(name, 256);
	std::cout << name << std::endl;

	std::string STRING;
	std::ifstream infile;
	infile.open(name);

	while (!infile.eof()) // To get you all the lines.
	{
		getline(infile, STRING); // Saves the line in STRING.
		std::string s ="yes";
		switch (eolCounter)
		{

		case 0:
			std::cout << "titlel:" << std::endl;
			break;
		case 1:
			std::cout << "hoeveel bj hoeveel:" << std::endl;
			// parse de dingen hier zodat je weet tot hoever hij gaat
			s = "";
			for (auto x : STRING)
			{
				if (x == ' ')
				{
					s = "";
					++counterForParse;
				}
				else
				{
					s += x;
					if (counterForParse == 0)
					{
						int tempString = stoi(s);
						amountOfJob = tempString;
					}
					else
					{
						int tempString = stoi(s);
						amountOfMachines = tempString;
					}
				}
			}
			std::cout << "amount of job: " << amountOfJob << " amount of machine: "
					<< amountOfMachines << std::endl;
			break;
		default:
			break;
		}

		if (eolCounter > 1 && eolCounter < 2 + amountOfJob)
		{
			std::cout << "regelnummer " << eolCounter << ": ";
		}
		else if (eolCounter > amountOfJob + 1)
		{
			eolCounter = -1;
			amountOfJob = 0;
			amountOfMachines = 0;
			counterForParse = 0;
		}
		std::cout << STRING << std::endl; // Prints our STRING.

		++eolCounter;

	}
	infile.close();
	return 0;
}
