/*
 * Job.cpp
 *
 *  Created on: 1 mrt. 2021
 *      Author: na_le
 */

#include "Job.h"

Job::Job()
{
	// TODO Auto-generated constructor stub

}

Job::~Job()
{
	// TODO Auto-generated destructor stub
}


int Job::getTotalDuration() const
{
	return totalDuration;
}

void Job::setTotalDuration(int totalDuration)
{
	this->totalDuration = totalDuration;
}
