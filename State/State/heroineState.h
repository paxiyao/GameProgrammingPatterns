#ifndef HEROINESTATE_H
#define HEROINESTATE_H
#include <iostream>

#include "heroine.h"

class HeroineState
{
public:
	virtual ~HeroineState() {}
	virtual HeroineState* handleInput(Input input) { return NULL; }
	// 进入状态调用
	virtual void enter(Heroine& heroine) {}
	// 退出状态调用
	virtual void exit(Heroine& heroine) {}
};

#endif // !HEROINESTATE_H