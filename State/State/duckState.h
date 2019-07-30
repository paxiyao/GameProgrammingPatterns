#ifndef DUCKSTATE_H
#define DUCKSTATE_H

#include "onGroundState.h"

class DuckState : public OnGroundState
{
public:
	virtual HeroineState* handleInput(Input input);
	virtual void enter(Heroine& heroine);
	virtual void exit(Heroine& heroine);
};

#endif // !DUCKSTATE_H