#ifndef ACTOR_H
#define ACTOR_H

#include <iostream>

class Actor
{
public:
	Actor() :_currentSlapped(false) {}

	virtual ~Actor() {}

	virtual void update() = 0;

	void swap()
	{
		_currentSlapped = _nextSlapped;
		_nextSlapped = false;
	}

	void slap() { _nextSlapped = true; }

	bool isSlapped() { return _currentSlapped; }

	void setName(const char* name) { _name = name; }

	const char* getName() { return _name; }
private:
	bool _currentSlapped;
	bool _nextSlapped;
	const char* _name;
};

#endif // !ACTOR_H
