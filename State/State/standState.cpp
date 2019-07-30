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
		// ���ø��๫�õ����봦����,������д�ظ�����
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