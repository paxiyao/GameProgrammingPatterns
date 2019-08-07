#ifndef AUDIO_H
#define AUDIO_H

enum SoundId
{
	SOUND_SPROING
};

class Audio
{
public:
	void playSound(SoundId sound, double volume) {}
};

#endif // AUDIO_H