#ifndef COMEDIAN_H
#define COMEDIAN_H

#include "actor.h"

class Comedian : public Actor 
{
public:
	void face(Actor* actor) { _facing = actor; }

	virtual void update()
	{
		if (isSlapped())
		{
			std::cout << getName() << " was slapped," << " so he slaps " << _facing->getName() << "\n" << std::endl;
			_facing->slap();
		}
		else
		{
			std::cout << getName() << " was not slapped," << " so he does nothing\n" << std::endl;
		}
	}
private:
	Actor* _facing;
};

#endif // !COMEDIAN_H
