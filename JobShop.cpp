/*
 * JobShop.cpp
 *
 *  Created on: 1 mrt. 2021
 *      Author: na_le
 */

#include "JobShop.h"
#include <iostream>

JobShop::JobShop(int longestJob = 0) :
		longestJob(0)
{
	// TODO Auto-generated constructor stub
}

JobShop::~JobShop()
{
	// TODO Auto-generated destructor stub
}

int JobShop::calcLongestJob() const
{
	int longestJob = 0;
	int i = 0;

	for (auto x : JobList)
	{
		std::cout << "x: " << x.getTotalDuration() << "vs:"
				<< JobList.at(longestJob).getTotalDuration() << std::endl;
		if (JobList.at(longestJob).getTotalDuration() < x.getTotalDuration())
		{
			longestJob = i;
		}
		++i;
	}
	return longestJob;
}


int JobShop::getLongestJobIndex() const
{
	return longestJob;
}

void JobShop::setLongestJob(int longestJob)
{
	this->longestJob = longestJob;
}

void JobShop::AddToJoblist(Job j)
{
	JobList.push_back(j);

}

void JobShop::makeLeastSlack()
{

	std::cout << std::endl;
}

