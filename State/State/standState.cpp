#include "standState.h"
#include "duckState.h"

HeroineState* StandState::handleInput(Input input)
{
	if (input == PRESS_DOWN)
	{
		return new DuckState();
	}
	else
	{
		// 调用父类公用的输入处理方法,减少书写重复代码
		OnGroundState::handleInput(input);
	}

	return NULL;
}

void StandState::enter(Heroine& heroine)
{
	std::cout << "Enter StandState" << std::endl;
	heroine.setGraphics(IMAGE_STAND);
}

void StandState::exit(Heroine& heroine)
{
	heroine.popState();
}