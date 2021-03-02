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
	virtual ~Task();
	int getDuration() const;
	void setDuration(int duration);
	int getMachine() const;
	void setMachine(int machine);

private:
	int machine;
	int duration;

};

#endif /* TASK_H_ */
