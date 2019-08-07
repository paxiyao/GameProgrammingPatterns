#ifndef PARTICLE_H
#define PARTICLE_H

enum ParticleType
{
	PARTICLE_DUST
};

class Particle
{
public:
	void spawnParticles(ParticleType type, int count) {}
};

#endif // PARTICLE_H