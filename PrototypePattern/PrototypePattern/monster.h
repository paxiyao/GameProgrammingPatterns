#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>

class Monster
{
public:
	virtual ~Monster() { }
};

class Ghost : public Monster 
{
public:
	Ghost() { std::cout << "Ghost Construcor!" << std::endl; }
};

class Demon : public Monster {};

class Sorcerer : public Monster {};

Monster* spawnGhost() { return new Ghost(); }

Monster* spawnDemon() { return new Demon(); }

Monster* spawnSorcerer() { return new Sorcerer(); }

#endif // !MONSTER_H
