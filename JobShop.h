/*
 * JobShop.h
 *
 *  Created on: 1 mrt. 2021
 *      Author: na_le
 */

#ifndef JOBSHOP_H_
#define JOBSHOP_H_
#include <vector>
#include "Job.h"

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


private:
	int longestJob;
	std::vector<Job> JobList;
};

#endif /* JOBSHOP_H_ */
