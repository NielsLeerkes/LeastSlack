/*
 * Main.cpp
 *
 *  Created on: 2 mrt. 2021
 *      Author: na_le
 */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "JobShop.h"
#include "Job.h"
#include "Task.h"

#include <vector>
int main(int argc, char **argv)
{
	int x;
	char name[256];

	std::cout << "Enter the file name:";
	std::cin.getline(name, 256);
	std::cout << name << std::endl;

	std::ifstream istrm;
	istrm.open(name);

//	JobShop shopA;
//	shopA.getLongestJob();
//	shopA.getLongestJob();
	int eolCounter = 0;
	std::vector<int> list =
	{ };
	while (istrm >> x)
	{
		if (x == '\0')
		{
			std::cout << "eolcounter: "<<eolCounter << std::endl;

			if (eolCounter == 0)
			{
				++eolCounter;
			}
			else
			{
				std::cout << "making list now" << std::endl;
				std::vector<Task> taskList =
				{ };
				for (size_t i = 0; i < list.size(); i = i + 2)
				{
					Task a(list.at(i), list.at(i + 1));
					taskList.push_back(a);
				}
				Job jobA = (taskList);
				std::cout << "total duration job: " << jobA.getTotalDuration()
						<< std::endl;
				std::cout << "list cleared time for a new one" << std::endl;
				list.clear();
			}

		}
		if (eolCounter != 0)
		{
			std::cout << "adding:" << x << " to the list" << std::endl;
			list.push_back(x);

		}
		std::cout << x << std::endl;
	}
	istrm.close();

//	auto begin = taskList.begin();
//	auto end = taskList.end();
//	auto print =
//			[](
//					const Task &n)
//					{	std::cout << "Machine : " << n.getMachine() << " " << "Duration " << n.getDuration() << std::endl;};
//	std::for_each(begin, end, print);

	return 0;
}
