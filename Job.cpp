/*
 * Job.cpp
 *
 *  Created on: 1 mrt. 2021
 *      Author: na_le
 */

#include "Job.h"
#include <iostream>

Job::Job(std::vector<Task> jobList) :
		jobList(jobList)
{
	// TODO Auto-generated constructor stub
	int totalDuration = 0;
	std::cout << jobList.size();
	for (size_t i = 0; i < jobList.size(); ++i)
	{
		totalDuration += jobList.at(i).getDuration();
	}
	this->totalDuration = totalDuration;
	std::cout << totalDuration << std::endl;

}

Job::~Job()
{
	// TODO Auto-generated destructor stub
}

int calcTotalDuration(std::vector<Task> jobList)
{
	return 0;

}

int Job::getTotalDuration() const
{
	return totalDuration;
}

void Job::setTotalDuration(int totalDuration)
{
	this->totalDuration = totalDuration;
}
