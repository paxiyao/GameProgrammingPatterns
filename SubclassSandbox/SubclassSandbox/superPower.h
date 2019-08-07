#ifndef SUPER_POWER_H
#define SUPER_POWER_H

#include "audio.h"
#include "particle.h"

class SuperPower
{
public:
	virtual ~SuperPower() 
	{
		if (_audio != nullptr)
		{
			delete _audio;
		}

		if (_particle != nullptr)
		{
			delete _particle;
		}
	}
	static void init(Audio* audio, Particle* particle)
	{
		_audio = audio;
		_particle = particle;
	}
	virtual void activate() = 0;
protected:
	static Audio* getAudio() { return _audio; }
	static Particle* getParticle() { return _particle; }

	void playSound(SoundId id, double volume)
	{
		_audio->playSound(id, volume);
	}

	void spawnParticles(ParticleType type, int count)
	{
		_particle->spawnParticles(type, count);
	}
private:
	static Audio* _audio;
	static Particle* _particle;
};


Audio* SuperPower::_audio = nullptr;
Particle* SuperPower::_particle = nullptr;

#endif // SUPER_POWER_H
