/*
 * Task.h
 *
 *  Created on: 1 mrt. 2021
 *      Author: na_le
 */

#ifndef TASK_H_
#define TASK_H_



class Task
{
public:

	Task();
	Task(int machine, int duration,int id);
	Task(const Task& otherTaks);
	Task operator=(const Task& task);
	virtual ~Task();
	int getDuration() const;
	void setDuration(int duration);
	int getMachine() const;
	void setMachine(int machine);
	int getId() const;
	void reduceDuration();

private:
	int id;
	int machine;
	int duration;
	bool finished;

};

#endif /* TASK_H_ */
