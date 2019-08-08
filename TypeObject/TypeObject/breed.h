#ifndef BREED_H
#define BREED_H

#include <iostream>

class Monster;

class Breed
{
public:
	Breed(Breed* parent, int health, const char* attack);

	Monster* newMonster();

	int getHealth();

	const char* getAttack();
private:
	int _health;
	const char* _attack;
};


#endif // BREED_H
