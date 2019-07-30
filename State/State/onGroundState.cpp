#include "onGroundState.h"
#include "standState.h"
#include "duckState.h"

HeroineState* OnGroundState::handleInput(Input input)
{
	if (input == PRESS_UP)
	{
		return new StandState();
	}
	else if (input == PRESS_DOWN)
	{
		return new DuckState();
	}
	else if (input == PRESS_A)
	{
		//return new DuckState();
	}
	else if (input == PRESS_B)
	{
		//return new DuckState();
	}

	return NULL;
}