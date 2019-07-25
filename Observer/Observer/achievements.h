#ifndef ACHIEVEMENTS_H
#define ACHIEVEMENTS_H

#include "observer.h"

class Achievements: public Observer
{
public:
	virtual ~Achievements() { }
	virtual void  onNotify(Event event)
	{
		switch (event)
		{
		case ACHIEVEMENT_FELL_OFF_BRIDGE:
			this->unlock(ACHIEVEMENT_FELL_OFF_BRIDGE);
			break;
		default:
			break;
		}
	}
private:
	void unlock(Event event)
	{
		std::cout << "UNLOCK ACHIEVEMENT_FELL_OFF_BRIDGE SUCCESS" << std::endl;
	}
};

#endif // !ACHIEVEMENTS_H

