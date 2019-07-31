#ifndef SCENE_H
#define SCENE_H

#include "frameBuffer.h"

class Scene
{
public:
	Scene() :_current(&_buffer[0]), _next(&_buffer[1]) {}
	
	void draw()
	{
		_next->clear();

		_next->draw(1, 1);
		_next->draw(4, 1);
		_next->draw(1, 3);
		_next->draw(2, 4);
		_next->draw(3, 4);
		_next->draw(4, 3);

		swap();
	}

	FrameBuffer& getBuffer() { return *_current; }

	void swap()
	{
		// Just switch the pointers.
		FrameBuffer* temp = _current;
		_current = _next;
		_next = temp;
	}
private:
	FrameBuffer _buffer[2];
	FrameBuffer* _current;
	FrameBuffer* _next;
};


#endif // !SCENE_H
