#include "JobShop.h"
#include <iostream>
#include <sstream>

JobShop::JobShop(int longestJob = 0) :
		longestJob(longestJob)
{
	amountOfJobs = 0;
	amountOfMachines = 0;
}

JobShop::~JobShop()
{
}
void JobShop::setJobName(std::string name)
{
	this->name = name;
	std::cout << "name of the job: " << this->name << std::endl;
}


std::vector<std::string> JobShop::parseString(const std::string &inputString)
{
	std::vector<std::string> split;
	std::stringstream ss(inputString);
	std::string item;
	char delim = ' ';
	while(getline(ss, item, delim))
	{
		split.push_back(item);
	}
	return split;	
}

void JobShop::setJobDetails(const std::string &detailString)
{
	std::vector<std::string> split = parseString(detailString);
	this->amountOfJobs = std::stoi(split.at(0));
	this->amountOfMachines = std::stoi(split.at(1));

	std::cout << "amound of jobs: " << this->amountOfJobs << " amount of machines: " << this->amountOfMachines << std::endl;
}

int JobShop::setJobList(std::string input)
{
	return 0;
}

int JobShop::calcLongestJob() const
{
	int longestJob = 0;
	int i = 0;

	for (auto x : JobList)
	{
		if (JobList.at(longestJob).getTotalDuration() < x.getTotalDuration())
		{
			longestJob = i;
		}
		++i;
	}
	return longestJob;
}


int JobShop::getLongestJobIndex() const
{
	return longestJob;
}

void JobShop::setLongestJob(int longestJob)
{
	this->longestJob = longestJob;
}

void JobShop::AddToJoblist(Job j)
{
	JobList.push_back(j);

}

void JobShop::makeLeastSlack()
{
	JobList.at(longestJob).setBeginTime(0);

	JobList.at(longestJob).setCurrentTime(JobList.at(longestJob).getTaskList().at(0).getDuration());

	for(auto x : JobList.at(longestJob).getTaskList())
	{
		std::cout << x.getMachine()<< " "<< x.getDuration() <<'\t';
	}
	std::cout<<std::endl;

	JobList.at(longestJob).getTaskList().erase(JobList.at(longestJob).getTaskList().begin());

	std::cout << "current time: " << JobList.at(longestJob).getCurrentTime()<< std::endl;

	for(auto x : JobList.at(longestJob).getTaskList())
	{
		std::cout << x.getMachine()<< " "<< x.getDuration() <<'\t';
	}
	std::cout<<std::endl;


	int x = 0;
	for(auto a : JobList)
	{
		std::cout << "index: " << x << " begintime: "<< a.getBeginTime();
		std::cout << " endtime:  " << a.getEndTime() << std::endl;
	}
}

