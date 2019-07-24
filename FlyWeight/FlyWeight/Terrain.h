#ifndef TERRAIN_H
#define TERRAIN_H

class Terrain
{
public:
	Terrain(int movementCost, bool isWater, int texture)
		:_movementCost(movementCost), _isWater(isWater), _texture(texture)
	{ }
	int getMovementCost() const { return _movementCost; }
	bool isWater() const{ return _isWater; }
	int getTexture() const { return _texture; }
private:
	int _movementCost;
	bool _isWater;
	int _texture;
};


#endif // !TERRAIN_H

