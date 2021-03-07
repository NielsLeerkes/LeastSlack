/*
 * JobShop.cpp
 *
 *  Created on: 1 mrt. 2021
 *      Author: na_le
 */

#include "JobShop.h"



JobShop::JobShop(int longsetJob, std::vector<Job> JobList) : longestJob (0),  JobList (JobList)
{
	// TODO Auto-generated constructor stub
}


JobShop::~JobShop()
{
	// TODO Auto-generated destructor stub
}

int JobShop::getLongestJob() const
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
