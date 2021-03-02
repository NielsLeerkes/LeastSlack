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
#include "Job.h"
#include "Task.h"

#include <vector>
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
//	shopA.getLongestJob();
	int eolCounter = 0;
	std::vector<int> list ={};
	while (istrm >> x)
	{
		if (x == '\0')
		{
			std::cout << std::endl;
			if (eolCounter != 0){
//				shopA.AddToJoblist(Job a());
			}

			++eolCounter;

		}
		if (eolCounter != 0)
		{
			list.push_back(x);

		}

	}
	istrm.close();


	for (int i =0; i < list.size(); i = i+2)
	{
		Task a(list.at(i), list.at(i + 1));

	}
	return 0;
}
