#ifndef MOVECOMMAND_H
#define MOVECOMMAND_H

#include "command.h"

class MoveCommand : public Command
{
public:
	virtual void execute()
	{
		std::cout << "MoveCommand" << std::endl;
	}

	virtual void undo()
	{
	}
};

#endif // !MOVECOMMAND_H

