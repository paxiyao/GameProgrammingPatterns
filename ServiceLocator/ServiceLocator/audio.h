#ifndef AUDIO_H
#define AUDIO_H

#include <string>

class Audio
{
public:
	virtual void playSound(int soundId) = 0;
	virtual void stopSound(int soundId) = 0;
	virtual void stopAllSounds() = 0;
};

#endif