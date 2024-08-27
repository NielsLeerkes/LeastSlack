/*
 * Job.cpp
 *
 *  Created on: 1 mrt. 2021
 *      Author: na_le
 */

#include "Job.h"
#include <iostream>

Job::Job(std::vector<Task> jobList) :currentTime (0),beginTime (0), endTime(0),taskList(jobList)
{
	int totalDuration = 0;
	for (auto x : jobList)
	{
		totalDuration += x.getDuration();
	}
	this->totalDuration = totalDuration;
}

Job::~Job()
{
	// TODO Auto-generated destructor stub
}

std::vector<Task> Job::getTaskList()
{
	return taskList;
}

int Job::getTotalDuration() const
{
	return totalDuration;
}

void Job::setTotalDuration(int totalDuration)
{
	this->totalDuration = totalDuration;
}

int Job::getBeginTime() const
{
	return beginTime;
}

void Job::setBeginTime(int beginTime)
{
	this->beginTime = beginTime;
}

int Job::getEndTime() const
{
	return endTime;
}

void Job::setEndTime(int endTime)
{
	this->endTime = endTime;
}

int Job::getCurrentTime() const
{
	return currentTime;
}

void Job::setCurrentTime(int currentTime)
{
	this->currentTime = currentTime;
}
