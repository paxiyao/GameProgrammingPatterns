#include "heroine.h"
#include "heroineState.h"

Heroine::Heroine(HeroineState* state)
{
	pushState(state);
	state->enter(*this);
}

void Heroine::handleInput(Input input)
{
	unsigned int size = _vecState.size();

	if (size == 0) return;

	HeroineState* state = _vecState[size - 1]->handleInput(input);
	if (state != NULL)
	{
		//// ����״̬��
		//delete _state;
		//_state = state;

		//// ÿ�ν���һ���µ�״̬����
		//_state->enter(*this);

		// �����Զ���
		// ÿ�ν���һ���µ�״̬����
		state->enter(*this);
		pushState(state);
	}
}

void Heroine::setGraphics(Image image)
{
	switch (image)
	{
	case IMAGE_STAND:
		std::cout << "IMAGE_STAND" << std::endl;
		break;
	case IMAGE_DUCK:
		std::cout << "IMAGE_DUCK" << std::endl;
		break;
	default:
		break;
	}
}

void Heroine::pushState(HeroineState* state)
{
	_vecState.push_back(state);
}

void Heroine::popState()
{
	_vecState.pop_back();
	_vecState[_vecState.size() - 1]->enter(*this);
}