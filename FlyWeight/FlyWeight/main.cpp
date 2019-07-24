// 享元模式: 使用共享以高效地支持大量的细粒度对象
// 必须保证所有的共享数据是内在的或者上下文无关的
// 对象实例可以放在需要的时候生产

#include "World.h"

int main()
{
	World* world = new World();
	world->generateTerrain();
	const Terrain& tr = world->getTile(4, 5);
	return 0;
}