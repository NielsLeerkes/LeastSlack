/*
 * JobShop.h
 *
 *  Created on: 1 mrt. 2021
 *      Author: na_le
 */

#ifndef JOBSHOP_H_
#define JOBSHOP_H_
#include "Job.h"
#include <iostream>
#include <string>
#include <vector>

class JobShop
{
public:
	JobShop(int longestJob);
	virtual ~JobShop();
	int calcLongestJob() const;
	void setLongestJob(int longestJob);
	void AddToJoblist(Job j);
	int getLongestJobIndex() const;
	void makeLeastSlack();

	std::vector<std::string> parseString(const std::string &inputString);	
	void setJobName(std::string name);
	void setJobDetails(const std::string &detailString);
	int setJobList(std::string input);


private:
	int amountOfMachines;
	int amountOfJobs;
	std::string name;
	int longestJob;
	std::vector<Job> JobList;
};

#endif /* JOBSHOP_H_ */
