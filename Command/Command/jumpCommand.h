#ifndef JUMPCOMMAND_H
#define JUMPCOMMAND_H

#include "command.h"

class JumpCommand : public Command
{
public:
	JumpCommand(Unit* unit, int x, int y)
		:_unit(unit), _x(x), _y(y), _xBefore(0), _yBefore(0)
	{ }
	virtual void execute()
	{
		_xBefore = _unit->_x;
		_yBefore = _unit->_y;
		_unit->moveTo(_x, _y);
	}
	virtual void undo()
	{
		_unit->moveTo(_xBefore, _yBefore);
	}
private:
	Unit* _unit;
	int _x;
	int _y;
	int _xBefore;
	int _yBefore;
};

#endif // !JUMPCOMMAND_H

