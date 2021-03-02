/*
 * JobShop.cpp
 *
 *  Created on: 1 mrt. 2021
 *      Author: na_le
 */

#include "JobShop.h"

JobShop::JobShop()
{
	// TODO Auto-generated constructor stub

}

JobShop::~JobShop()
{
	// TODO Auto-generated destructor stub
}

int JobShop::getLongestJob() const
{
	return longestJob;
}

void JobShop::setLongestJob(int longestJob)
{
	this->longestJob = longestJob;
}
