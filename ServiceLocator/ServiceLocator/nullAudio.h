#ifndef NULL_AUDIO_H
#define NULL_AUDIO_H

#include "audio.h"

class NullAudio : public Audio
{
public:
	virtual void playSound(int soundId)
	{
		// do nothings
	}

	virtual void stopSound(int soundId)
	{
		// do nothings
	}

	virtual void stopAllSounds()
	{
		// do nothings
	}
};

#endif // NULL_AUDIO_H