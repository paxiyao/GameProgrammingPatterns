#ifndef OBSERVER_H
#define OBSERVER_H
#include <iostream>

#include "event.h"
#include "subject.h"

class Observer
{
	friend class Subject;
public:
	Observer() :_next(NULL) { }
	virtual ~Observer() 
	{ 
		if (_subject)
			_subject->removeObserver(this);
	}
	virtual void  onNotify(Event event) = 0;
private:
	Observer* _next;
	Subject* _subject;
};

#endif // !OBSERVER_H

