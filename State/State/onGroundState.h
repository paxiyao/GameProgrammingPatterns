#ifndef ONGROUNDSTATE_H
#define ONGROUNDSTATE_H

#include "heroineState.h"

class OnGroundState:public HeroineState
{
public:
	virtual HeroineState* handleInput(Input input);
};

#endif // !ONGROUNDSTATE_H