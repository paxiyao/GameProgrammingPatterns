#ifndef STAGE_H
#define STAGE_H

#include "actor.h"

class Stage
{
public:
	void addActor(Actor* actor, int index)
	{
		_actors[index] = actor;
	}

	void update()
	{
		// ×´Ì¬·ÃÎÊ
		for (unsigned int i = 0; i < NUM_ACTOR; i++)
		{
			std::cout << "Stage updates actor" << i << " (" << _actors[i]->getName() << ")\n" << std::endl;
			_actors[i]->update();
		}

		std::cout << "State update end\n" << std::endl;

		// ×´Ì¬ÐÞ¸Ä
		for (unsigned int i = 0; i < NUM_ACTOR; i++)
		{
			_actors[i]->swap();
		}
	}
private:
	static const int NUM_ACTOR = 3;
	Actor* _actors[NUM_ACTOR];
};

#endif // !STAGE_H
