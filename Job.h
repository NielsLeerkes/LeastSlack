/*
 * Job.h
 *
 *  Created on: 1 mrt. 2021
 *      Author: na_le
 */

#ifndef JOB_H_
#define JOB_H_

#include <vector>

#include "Task.h"

class Job
{
public:
	Job(std::vector<Task> jobList);
	virtual ~Job();

	int getTotalDuration() const;
	void setTotalDuration(int totalDuration);
	int calcTotalDuration(std::vector<Task> jobList);
	void addTOJobList();

private:
	std::vector<Task> jobList = {};
	int totalDuration;
};

#endif /* JOB_H_ */
