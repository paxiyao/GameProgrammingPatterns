#ifndef STANDSTATE_H
#define STANDSTATE_H

#include "onGroundState.h"

class StandState: public OnGroundState
{
public:
	virtual HeroineState* handleInput(Input input);
	virtual void enter(Heroine& heroine);
	virtual void exit(Heroine& heroine);
};

#endif // !STANDSTATE_H