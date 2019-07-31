#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

enum Color
{
	WHITE,
	BLACK
};

class FrameBuffer
{
public:
	FrameBuffer()
	{

	}

	void clear()
	{
		for (unsigned int i = 0; i < WIDTH * HEIGHT; i++)
		{
			_pixels[i] = WHITE;
		}
	}

	void draw(int x, int y)
	{
		_pixels[(WIDTH * y) + x] = BLACK;
	}

	const char* getPixel()
	{
		return _pixels;
	}

private:
	static const  int WIDTH = 160;
	static const int HEIGHT = 120;

	char _pixels[WIDTH * HEIGHT];
};


#endif // !FRAMEBUFFER_H
