#include "JobShop.h"
#include <iostream>
#include <sstream>
#include <cstring>

JobShop::JobShop(int longestJob = 0) :
		longestJob(longestJob)
{
	amountOfJobs = 0;
	amountOfMachines = 0;
}

JobShop::~JobShop()
{
}

void JobShop::clearJobShop()
{
	for(auto job :jobList)
	{
		job.getTaskList().clear();
	}
	jobList.clear();
}

void JobShop::setJobName(std::string name)
{
	this->name = name;
}


void JobShop::printJobShop()
{
	std::cout << "===================================================" << std::endl;
	std::cout << "Job name: " << this->name <<std::endl;
	std::cout << "amount of jobs: " << this->amountOfJobs <<std::endl << "Amount of machines: " << this-> amountOfMachines << std::endl;
	// for loop to print all the data 
	int i = 0;
	for(int i = 0; i < this->jobList.size(); ++i)
	{
		for(int y = 0; y < this->jobList.at(i).getTaskList().size(); ++y)
		{
		 	std::cout << jobList.at(i).getTaskList().at(y).getMachine() << " " << jobList.at(i).getTaskList().at(y).getDuration()<< ", "; 
		}
		std::cout<< ::std::endl;
	}

	std::cout << "===================================================" << std::endl<<std::endl;

}

std::vector<std::string> JobShop::parseString(const std::string &inputString)
{
	std::string cleanedString = inputString;
	std::string replace_spaces = "  "; 
    std::string replace_by = " "; 
  
    size_t pos = cleanedString.find(replace_spaces); 
  
    while (pos != std::string::npos) { 
        cleanedString.replace(pos, replace_spaces.size(), replace_by); 
        pos = cleanedString.find(replace_spaces, 
                         pos + replace_by.size()); 
    } 

	std::string replace_tabs = "\t"; 
    std::string replace_by2 = " "; 
    size_t pos2 = cleanedString.find(replace_tabs); 
    while (pos2 != std::string::npos) { 
        cleanedString.replace(pos2, replace_tabs.size(), replace_by2); 
        pos2 = cleanedString.find(replace_tabs, 
                         pos2 + replace_by2.size()); 
    } 
	std::vector<std::string> split;
	std::stringstream ss(cleanedString);
	std::string item;
	char delim = ' ';
	while(getline(ss, item, delim))
	{
		split.push_back(item);
	}
	int index = 0;
	for(auto x: split)
	{	
		if(x.size() == 0)
		{
			split.erase(split.begin() + index);
		}
		++index;
	}
	return split;	
}

void JobShop::setJobDetails(const std::string &detailString)
{
	std::vector<std::string> split = parseString(detailString);
	this->amountOfJobs = std::stoi(split.at(0));
	this->amountOfMachines = std::stoi(split.at(1));
}

int JobShop::setJobList(const std::string &input)
{
	std::vector<std::string> split = parseString(input);
	std::vector<Task> taskList;
	int index = 0;
	for(int i = 0; i < split.size() / 2; ++i)
	{
		Task t(std::stoi(split.at(index)),std::stoi(split.at(index +1)));
		taskList.push_back(t);
		index+=2;
	}
	Job job(taskList);
	jobList.push_back(job);
	return 0;
}

int JobShop::calcLongestJob() const
{
	int longestJob = 0;
	int i = 0;

	for (auto x : jobList)
	{
		if (jobList.at(longestJob).getTotalDuration() < x.getTotalDuration())
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
	jobList.push_back(j);

}

void JobShop::makeLeastSlack()
{
	jobList.at(longestJob).setBeginTime(0);

	jobList.at(longestJob).setCurrentTime(jobList.at(longestJob).getTaskList().at(0).getDuration());

	for(auto x : jobList.at(longestJob).getTaskList())
	{
		std::cout << x.getMachine()<< " "<< x.getDuration() <<'\t';
	}
	std::cout<<std::endl;

	jobList.at(longestJob).getTaskList().erase(jobList.at(longestJob).getTaskList().begin());

	std::cout << "current time: " << jobList.at(longestJob).getCurrentTime()<< std::endl;

	for(auto x : jobList.at(longestJob).getTaskList())
	{
		std::cout << x.getMachine()<< " "<< x.getDuration() <<'\t';
	}
	std::cout<<std::endl;


	int x = 0;
	for(auto a : jobList)
	{
		std::cout << "index: " << x << " begintime: "<< a.getBeginTime();
		std::cout << " endtime:  " << a.getEndTime() << std::endl;
	}
}

