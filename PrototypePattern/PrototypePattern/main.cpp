// ԭ�����ģʽ:ʹ��һ�������ԭ��,ȥ��¡һ������,������ʹ��newȥ����,Ȼ����и�ֵ
// spawn�ཫmonster���Ͳ���������c++�У�����ͨ������һ���ģ���������ҪһЩ���ɡ����ʹ�ö�̬�������ԣ���JavaScript��Python��Ruby���������ǿ��Դ��ݵĳ����������Ը�ֱ�ӵؽ���������
#include "spawn.h"

int main()
{
	Ghost* ghost = new Ghost();
	Spawn* spawnGho = new Spawn(spawnGhost);
	Monster* newGhost = spawnGho->spawnMonster();
	system("pause");
	return 0;
}