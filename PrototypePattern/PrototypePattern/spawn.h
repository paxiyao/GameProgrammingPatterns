#ifndef SPAWN_H
#define SPAWN_H

#include "monster.h"

typedef Monster* (*SpawnCallback) ();

class Spawn
{
public:
	Spawn(SpawnCallback spawn)
		:_spawn(spawn)
	{ }
	
	Monster* spawnMonster()
	{
		return _spawn();
	}
private:
	SpawnCallback _spawn;
};

#endif // !SPAWN_H
