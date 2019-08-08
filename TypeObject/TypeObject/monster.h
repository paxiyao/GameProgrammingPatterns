#ifndef MONSTER_H
#define MONSTER_H

class Monster
{
	friend class Breed;
public:
	const char* getAttac() { return _breed.getAttack(); }
private:
	Monster(Breed& bread)
		:_heathy(bread.getHealth()),
		_breed(bread)
	{}
	
	Breed& _breed;
	int _heathy;
};

#endif // MONSTER_H
