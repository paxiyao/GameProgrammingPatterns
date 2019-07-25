#ifndef SUBJECT_H
#define SUBJECT_H
#include <iostream>

#include "event.h"

class Subject
{
public:
	Subject() :_header(NULL) { }

	virtual ~Subject() 
	{ 
		// 通知观察者,被观察者销毁
		this->onNotify(DESTROY_SUBJECT);
	}

	void onNotify(Event event)
	{
		Observer* observer = _header;
		while (observer != NULL)
		{
			observer->onNotify(event);
			observer = observer->_next;
		}
	}

	void addObserver(Observer* observer)
	{
		observer->_subject = this;
		observer->_next = _header;
		_header = observer;
	}

	void removeObserver(Observer* observer)
	{
		if (_header == observer)
		{
			_header = observer->_next;
			observer->_next = NULL;
			return;
		}
		Observer* current = _header;
		while (current != NULL)
		{
			if (current == observer)
			{
				current->_next = observer->_next;
				observer->_next = NULL;
				return;
			}
			current = observer->_next;
		}
	}
private:
	Observer* _header;
};

#endif // !SUBJECT_H

