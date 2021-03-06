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

	std::vector<int> helpVector1;

	std::string wholeLine;
	std::ifstream infile;
	infile.open(name);
	JobShop shoppie(1);
	while (!infile.eof()) // To get you all the lines.
	{
		getline(infile, wholeLine); // Saves the line in STRING.
		std::string s = "yes";
		std::string s2 = "dick";
		switch (eolCounter)
		{

		case 0:
			std::cout << "titlel:" << std::endl;
			break;
		case 1:
//			std::cout << "hoeveel bj hoeveel:" << std::endl;
			s = "";
			for (auto x : wholeLine)
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
			counterForParse = 0;
			s= "";
			std::cout << "amount of machines: " << amountOfMachines
					<< std::endl;
			std::cout << "amount of jobs: " << amountOfJob << std::endl;
			counterForParse = 0;
			break;
		default:
			break;
		}

		if (eolCounter > 1 && eolCounter < 2 + amountOfJob)
		{
			s2 = "";
			for (auto x : wholeLine)
			{
				if (x == ' ')
				{

					int tempString2 = stoi(s2);
					helpVector1.push_back(tempString2);
					s2 = "";
				}
				else
				{
					s2 += x;
				}
			}
			int tempString2 = stoi(s2);
			helpVector1.push_back(tempString2);
			s2 = "";
			std::vector<Task> jobList;
			for (int i = 0; i < amountOfMachines * 2; i += 2)
			{
				Task task(helpVector1.at(i), helpVector1.at(i + 1));
				jobList.push_back(task);
			}
			Job job(jobList);
			shoppie.AddToJoblist(job);
			helpVector1.clear();
		}
		if (eolCounter > amountOfJob + 1)
		{
			eolCounter = -1;
			amountOfJob = 0;
			amountOfMachines = 0;
		}
		std::cout << wholeLine << std::endl; // Prints our STRING.
		++eolCounter;
	}

	shoppie.setLongestJob(shoppie.calcLongestJob());
	shoppie.makeLeastSlack();
	infile.close();

	return 0;
}
