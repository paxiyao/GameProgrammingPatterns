// ��Ԫģʽ: ʹ�ù����Ը�Ч��֧�ִ�����ϸ���ȶ���
// ���뱣֤���еĹ������������ڵĻ����������޹ص�
// ����ʵ�����Է�����Ҫ��ʱ������

#include "World.h"

int main()
{
	World* world = new World();
	world->generateTerrain();
	const Terrain& tr = world->getTile(4, 5);
	return 0;
}