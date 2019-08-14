#ifndef CONSOLE_AUDIO_H
#define CONSOLE_AUDIO_H

#include "audio.h"

class ConsoleAudio : public Audio
{
public:
	virtual void playSound(int soundId)
	{
		// do things
	}

	virtual void stopSound(int soundId)
	{
		// do things
	}

	virtual void stopAllSounds()
	{
		// do things
	}
};

#endif // CONSOLE_AUDIO_H