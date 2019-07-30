#ifndef HEROINE_H
#define HEROINE_H
#include <vector>

#include "input.h"
#include "image.h"

class HeroineState;

class Heroine
{
public:
	Heroine(HeroineState* state);
	virtual void handleInput(Input input);
	virtual void setGraphics(Image image);
	virtual void pushState(HeroineState* state);
	virtual void popState();
private:
	HeroineState* _state;	// ¶¯×÷×´Ì¬
	HeroineState* _equipment;// ÎäÆ÷×´Ì¬
	std::vector<HeroineState*> _vecState;
};

#endif // !HEROINE_H