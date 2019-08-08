#include "breed.h"
#include "monster.h"

Breed::Breed(Breed* parent, int health, const char* attack)
	:_health(health),
	 _attack(attack)
{
	//1.如果在运行时将一个品种修改为不再覆盖或不再继承某些属性，那么这样做的好处是正确的。另一方面，它需要更多的内存(它必须保留指向其父级的指针)，而且速度更慢。每次查找属性时，它都必须遍历继承链。
	//2.如果我们可以依赖一个品种的属性不改变，一个更快的解决方案是在构建时应用继承。这称为“复制 - 向下”委托，因为我们在创建继承属性时将其复制到派生类型中
	if (parent != NULL)
	{
		if (health == 0)
		{
			_health = parent->getHealth();
		}
		if (attack == NULL)
		{
			_attack = parent->getAttack();
		}
	}
}


// 使类型对象更像类型:构造函数
// 用我们现在所拥有的，我们直接建造一个怪物，并负责传递它的品种。
// 这与在大多数OOP语言中实例化常规对象的方式有点相反——我们通常不会分配一块空白内存，然后给它类。
// 相反，我们在类本身上调用构造函数，它负责给我们一个新的实例。
Monster* Breed::newMonster()
{
	return new Monster(*this);
}

int Breed::getHealth()
{
	return _health;
}

const char* Breed::getAttack()
{
	return _attack;
}