// ԭ�����ģʽ:ʹ��һ�������ԭ��,ȥ��¡һ������,������ʹ��newȥ��������,�ٽ��и�ֵ����
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


// ԭ��ģʽ������������ģ��,�𵽺ܺõļ�Ч��
/*
// not proto
{
  "name": "goblin grunt",
  "minHealth": 20,
  "maxHealth": 30,
  "resists": ["cold", "poison"],
  "weaknesses": ["fire", "light"]
}

{
  "name": "goblin wizard",
  "minHealth": 20,
  "maxHealth": 30,
  "resists": ["cold", "poison"],
  "weaknesses": ["fire", "light"],
  "spells": ["fire ball", "lightning bolt"]
}

{
  "name": "goblin archer",
  "minHealth": 20,
  "maxHealth": 30,
  "resists": ["cold", "poison"],
  "weaknesses": ["fire", "light"],
  "attacks": ["short bow"]
}

// proto
{
  "name": "goblin grunt",
  "minHealth": 20,
  "maxHealth": 30,
  "resists": ["cold", "poison"],
  "weaknesses": ["fire", "light"]
}

{
  "name": "goblin wizard",
  "prototype": "goblin grunt",
  "spells": ["fire ball", "lightning bolt"]
}

{
  "name": "goblin archer",
  "prototype": "goblin grunt",
  "attacks": ["short bow"]
}
*/