#ifndef WORLD_H
#define WORLD_H
#include <random>

#include "Terrain.h"

const int WIDTH = 10;
const int HEIGHT = 10;

class World
{
public:
	World()
		:_grassTerrain(1, false, 1), _hillTerrain(2, false, 2), _riverTerrain(3, true, 3), _tiles() 
	{ }
	void generateTerrain()
	{
		std::default_random_engine e(10);
		for (unsigned int x = 0; x < WIDTH; x++)
		{
			for (unsigned int y = 0; y < HEIGHT; y++)
			{
				int randomValue = e() % 3;
				if (randomValue == 0)
				{
					_tiles[x][y] = &_hillTerrain;
				}
				else if (randomValue == 1)
				{
					_tiles[x][y] = &_grassTerrain;
				}
				else
				{
					_tiles[x][y] = &_riverTerrain;
				}
			}
		}
	}
	const Terrain& getTile(int x, int y) const
	{
		return *_tiles[x][y];
	}
private:
	Terrain _grassTerrain;
	Terrain _hillTerrain;
	Terrain _riverTerrain;
	Terrain* _tiles[WIDTH][HEIGHT];
};


#endif // !WORLD_H

