#ifndef AUDIO_H
#define AUDIO_H

#include "observer.h"

class Audio : public Observer
{
public:
	virtual ~Audio() { }
	virtual void  onNotify(const Entity& entity, Event event)
	{
		switch (event)
		{
		case ACHIEVEMENT_FELL_OFF_BRIDGE:
			this->playAudio(ACHIEVEMENT_FELL_OFF_BRIDGE);
			break;
		default:
			break;
		}
	}
private:
	void playAudio(Event event)
	{
		std::cout << "PLAYAUDIO ACHIEVEMENT_FELL_OFF_BRIDGE" << std::endl;
	}
};

#endif // !AUDIO_H

