// ×ÓÀàÉ³ºÐ

#include "skyLaunch.h"

int main()
{
	Audio* audio = new Audio();
	Particle* particle = new Particle();
	SuperPower::init(audio, particle);

	SkyLaunch* skyLaunch = new SkyLaunch();
	skyLaunch->activate();

	delete audio;
	delete particle;
	delete skyLaunch;

	return 0;
}