#include "JobShop.h"
#include <iostream>
#include <sstream>
#include <cstring>

JobShop::JobShop(int longestJob = 0) :
		longestJob(longestJob)
{
	amountOfJobs = 0;
	amountOfMachines = 0;
	finished = false;
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
	// printActiveMachineList();
	std::cout << "===================================================" << std::endl;
	std::cout << "Job name: " << this->name <<std::endl;
	std::cout << "amount of jobs: " << this->amountOfJobs <<std::endl << "Amount of machines: " << this-> amountOfMachines << std::endl;
	// for loop to print all the data 
	int i = 0;
	for(int i = 0; i < this->jobList.size(); ++i)
	{
		for(int y = 0; y < this->jobList.at(i).getTaskList().size(); ++y)
		{
		 	std::cout << "(id: " << this->jobList.at(i).getTaskList().at(y).getId()<< " "<<this->jobList.at(i).getTaskList().at(y).getMachine() << " " << this->jobList.at(i).getTaskList().at(y).getDuration()<< "), "; 
		}
		std::cout << "; total duration = "<< this->jobList.at(i).getTotalDuration()<< " begin time : " << jobList.at(i).getBeginTime()<< std::endl;
		std::cout << "is active : " << jobList.at(i).getRunningStatus() << std::endl; 
		std::cout<< ::std::endl;
	}
	std::cout << "Longest job at index: " << longestJob << std::endl;
	std::cout << "current time = " << currentTime << std::endl;
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
	// std::cout <<"input in setJobList: "<< input << std::endl;
	std::vector<Task> taskList;
	int index = 0;
	for(int i = 0; i < split.size() / 2; ++i)
	{
		Task t(std::stoi(split.at(index)),std::stoi(split.at(index +1)),i);
		taskList.push_back(t);
		index+=2;
	}
	Job job(taskList);
	jobList.push_back(job);
	return 0;
}

void JobShop::calcLongestJob()
{
	setLongestJob(0);
	int i = 0;
	int longest = 0;
	for (auto x : jobList)
	{
		if(jobList.at(longest).getTotalDuration() < x.getTotalDuration())
		{
			longest = i;
		}
		++i;
	}
	setLongestJob(longest);
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

void JobShop::activateJob(int jobNr)
{
	if(jobList.at(jobNr).getBeginTime() == -1)
	{
		jobList.at(jobNr).setBeginTime(currentTime);
	}
		jobList.at(jobNr).setRunningStatus(true);
		activeMachines.push_back(jobList.at(jobNr).getTaskList().at(0).getMachine());
}

void JobShop::printActiveMachineList()
{
	std::cout << "the following machines are active: " << std::endl;
	for(auto x : activeMachines)
	{
		std::cout << x << ",";
	}
	std::cout << std::endl;
}

void JobShop::schedule()
{
	// jobList.at(longestJob).setBeginTime(0);
	// activateJob(longestJob);
	int loops = 0;
	while( loops < 78)
	// while(!finished)
	{
		int index = 0;
		for(int jobNr = 0; jobNr < amountOfJobs; ++jobNr)
		{
			std::cout << "current jobnr: "<< jobNr <<std::endl;
			std::cout << "done status: " << jobList.at(jobNr).getDoneStatus() << std::endl;
			if(!jobList.at(jobNr).getDoneStatus())
			{
				//check if the job can be activated.
				int machineNr = jobList.at(jobNr).getTaskList().at(0).getMachine();
				// printActiveMachineList();
				std::cout << "checking for the following machine nr: "<< machineNr << std::endl; 
				if(!checkRunningMachine(machineNr) && !jobList.at(jobNr).getRunningStatus())
				{
					if(checkForFasterMachines(machineNr,jobList.at(jobNr)))
					// {
						activateJob(jobNr);
					// }
					// std::cout<< "machine: " << jobs.getTaskList().at(0).getMachine() << " not running:)"<<std::endl;
				}
				if(jobList.at(jobNr).getRunningStatus())
				{
					if(jobList.at(jobNr).getTaskList().at(0).getDuration() > 0)
					{
						tick(jobList.at(jobNr),jobNr);
					}else{
						// std::cout << "removing at index: " << index << std::endl;
						removeFirstInLine(jobList.at(jobNr),jobNr);
						jobList.at(jobNr).setRunningStatus(false);
						// printActiveMachineList();
						finished = finishCheck();
					}  
				}
			++index;
			}
		}
		index=0;
		printJobShop();
		++loops;
		++currentTime;
	}
}

bool JobShop::finishCheck()
{
	for(auto job : jobList)
	{
		if(job.getRunningStatus())
		{
			return false;
		}
	}
	return true;
}

bool JobShop::checkRunningMachine(int machineNr)
{
	bool alreadyRunning = false;
	for(auto machine: activeMachines) 
	{
		if(machine == machineNr)
		{
			return true;
		}
	}
	return false;
}

bool JobShop::checkForFasterMachines(int machineNr, Job currentJob){
	for(auto job : jobList)
	{
		std::cout <<"checking for the following machine nr: " << machineNr << " and the following machine number at job " << job.getTaskList().at(0).getMachine() << std::endl; 
		if(job.getTaskList().at(0).getMachine() == machineNr)
		{
			std::cout << "my duration = " << currentJob.getTotalDuration() << "other current duration = " << job.getTotalDuration() << std::endl;
			if(currentJob.getTotalDuration() < job.getTotalDuration())
			{
				return false;
			}
		}
	}
	return true;
}

void JobShop::removeFirstInLine(Job job,int index)
{
	if(job.getTaskList().size() > 0)
	{
		std::vector<Task> helperList;
		helperList =job.getTaskList();
		int machineNr = helperList.at(0).getMachine();
		removeFromActiveMachineList(machineNr);
		helperList.erase(helperList.begin());
		Job j = job;
		j.setTaskList(helperList);
		jobList.at(index) =j;
	}else{
		jobList.at(index).setDone();
	}
}

void JobShop::removeFromActiveMachineList(int machineNr)
{
	std::cout << "before" << std::endl;
	printActiveMachineList();
	int index= 0;
	int onIndex = 0;
	for(auto x : activeMachines)
	{
		if(machineNr = x)
		{
			onIndex = index;
		}
		++index;
	}
	activeMachines.erase(activeMachines.begin() + onIndex);
	std::cout << "atfer" << std::endl;
	printActiveMachineList();
}

void JobShop::tick(Job job,int index)
{
	Task currentTask = job.getTaskList().at(0);
	currentTask.reduceDuration();
	std::vector<Task> helperList;
	helperList = job.getTaskList();
	helperList.at(0) = currentTask;
	Job j = job;
	j.setTaskList(helperList);
	jobList.at(index) =j;
}

void JobShop::makeLeastSlack()
{
	jobList.at(longestJob).setBeginTime(0);

	// jobList.at(longestJob).setCurrentTime(jobList.at(longestJob).getTaskList().at(0).getDuration());

	for(auto x : jobList.at(longestJob).getTaskList())
	{
		std::cout << x.getMachine()<< " "<< x.getDuration() <<'\t';
	}
	std::cout<<std::endl;

	jobList.at(longestJob).getTaskList().erase(jobList.at(longestJob).getTaskList().begin());

	// std::cout << "current time: " << jobList.at(longestJob).getCurrentTime()<< std::endl;

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

