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
	JobList.at(longestJob).setBeginTime(0);

	JobList.at(longestJob).setCurrentTime(JobList.at(longestJob).getTaskList().at(0).getDuration());

	for(auto x : JobList.at(longestJob).getTaskList())
	{
		std::cout << x.getMachine()<< " "<< x.getDuration() <<'\t';
	}
	std::cout<<std::endl;

	JobList.at(longestJob).getTaskList().erase(JobList.at(longestJob).getTaskList().begin());

	std::cout << "current time: " << JobList.at(longestJob).getCurrentTime()<< std::endl;

	for(auto x : JobList.at(longestJob).getTaskList())
	{
		std::cout << x.getMachine()<< " "<< x.getDuration() <<'\t';
	}
	std::cout<<std::endl;


	int x = 0;
	for(auto a : JobList)
	{
		std::cout << "index: " << x << " begintime: "<< a.getBeginTime();
		std::cout << " endtime:  " << a.getEndTime() << std::endl;
	}
}

