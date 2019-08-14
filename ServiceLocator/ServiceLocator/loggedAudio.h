#ifndef LOGGED_AUDIO_H
#define LOGGED_AUDIO_H

#include "audio.h"

class LoggedAudio : public Audio
{
public:
	LoggedAudio(Audio &wrapped)
		: wrapped_(wrapped)
	{}

	virtual void playSound(int soundID)
	{
		log("play sound");
		wrapped_.playSound(soundID);
	}

	virtual void stopSound(int soundID)
	{
		log("stop sound");
		wrapped_.stopSound(soundID);
	}

	virtual void stopAllSounds()
	{
		log("stop all sounds");
		wrapped_.stopAllSounds();
	}

private:
	void log(const char* message)
	{
		// Code to log message...
	}

	Audio &wrapped_;
};

#endif // LOGGED_AUDIO_H