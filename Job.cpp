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
	int totalDuration = 0;
	for (size_t i = 0; i < jobList.size(); ++i)
	{
		totalDuration += jobList.at(i).getDuration();
	}
	this->totalDuration = totalDuration;
}

Job::~Job()
{
	// TODO Auto-generated destructor stub
}

int calcTotalDuration(std::vector<Task> jobList)
{
	return 0;

}

std::vector<Task> Job::getJobList()
{
	return jobList;
}

int Job::getTotalDuration() const
{
	return totalDuration;
}

void Job::setTotalDuration(int totalDuration)
{
	this->totalDuration = totalDuration;
}
