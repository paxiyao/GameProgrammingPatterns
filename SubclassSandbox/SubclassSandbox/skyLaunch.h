#ifndef SKY_LAUNCH_H
#define SKY_LAUNCH_H

#include "superPower.h"

class SkyLaunch: public SuperPower
{
public:
	virtual void activate()
	{
		// Spring into the air.
		playSound(SOUND_SPROING, 1.0f);
		spawnParticles(PARTICLE_DUST, 10);
	}
};

#endif // SKY_LAUNCH_H