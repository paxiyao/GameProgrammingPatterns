// 原型设计模式:使用一个对象的原型,去克隆一个对象,而不是使用new去创建对象,再进行赋值操作
// spawn类将monster类型参数化。在c++中，类型通常不是一流的，所以这需要一些技巧。如果使用动态类型语言，如JavaScript、Python或Ruby，其中类是可以传递的常规对象，则可以更直接地解决这个问题

#include "spawn.h"

int main()
{
	Ghost* ghost = new Ghost();
	Spawn* spawnGho = new Spawn(spawnGhost);
	Monster* newGhost = spawnGho->spawnMonster();
	system("pause");
	return 0;
}


// 原型模式可以用于数据模型,起到很好的简化效果
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