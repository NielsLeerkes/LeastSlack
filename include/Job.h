/*
 * Job.h
 *
 *  Created on: 1 mrt. 2021
 *      Author: na_le
 */

#ifndef JOB_H_
#define JOB_H_

#include <vector>
#include <string>
#include "Task.h"

class Job
{
public:
	Job(std::vector<Task> jobList);
	virtual ~Job();

	int getTotalDuration() const;
	void setTotalDuration(int totalDuration);
	int calcTotalDuration(std::vector<Task> jobList);
	std::vector<Task> getTaskList();
	void addTOJobList();
	//begintime
	int getBeginTime() const;
	void setBeginTime(int beginTime);
	//endtime
	int getEndTime() const;
	void setEndTime(int endTime);
	//currentTime
	int getCurrentTime() const;
	void setCurrentTime(int currentTime);

private:
	std::string name;
	int currentTime;
	int beginTime;
	int endTime;
	std::vector<Task> taskList;
	int totalDuration;
};

#endif /* JOB_H_ */
