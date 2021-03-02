/*
 * Task.cpp
 *
 *  Created on: 1 mrt. 2021
 *      Author: na_le
 */

#include "Task.h"

Task::Task()
{
	// TODO Auto-generated constructor stub

}

Task::~Task()
{
	// TODO Auto-generated destructor stub
}

int Task::getDuration() const
{
	return duration;
}

void Task::setDuration(int duration)
{
	this->duration = duration;
}

int Task::getMachine() const
{
	return machine;
}

void Task::setMachine(int machine)
{
	this->machine = machine;
}
