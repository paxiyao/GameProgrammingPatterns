#ifndef HEROINESTATE_H
#define HEROINESTATE_H
#include <iostream>

#include "heroine.h"

class HeroineState
{
public:
	virtual ~HeroineState() {}
	virtual HeroineState* handleInput(Input input) { return NULL; }
	// ����״̬����
	virtual void enter(Heroine& heroine) {}
	// �˳�״̬����
	virtual void exit(Heroine& heroine) {}
};

#endif // !HEROINESTATE_H