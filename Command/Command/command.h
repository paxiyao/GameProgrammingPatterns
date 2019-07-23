#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>

#include "unit.h"

class Command
{
public:
	virtual ~Command() { }
	virtual void execute() = 0;
	virtual void undo() = 0;
};

#endif // !COMMAND_H

