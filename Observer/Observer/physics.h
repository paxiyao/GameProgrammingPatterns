#ifndef PHYSICS_H
#define PHYSICS_H
#include <iostream>

#include "event.h"
#include "subject.h"
#include "entity.h"

class Physics :public Subject
{
private:
	void updateEntity(Entity& entity)
	{
		if (entity.isHero())
		{
			onNotify(ACHIEVEMENT_FELL_OFF_BRIDGE);
		}
	}
};

#endif // !PHYSICS_H

