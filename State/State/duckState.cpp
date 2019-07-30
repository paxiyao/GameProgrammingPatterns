#include "duckState.h"
#include "standState.h"

HeroineState* DuckState::handleInput(Input input)
{
	if (input == PRESS_UP)
	{
		return new StandState();
	}
	else
	{
		// ���ø��๫�õ����봦����,������д�ظ�����
		OnGroundState::handleInput(input);
	}
	
	return NULL;
}

void DuckState::enter(Heroine& heroine)
{
	std::cout << "Enter DuckState" << std::endl;
	heroine.setGraphics(IMAGE_DUCK);
}

void DuckState::exit(Heroine& heroine)
{
	heroine.popState();
}