#ifndef UNIT_H
#define UNIT_H

class Unit
{
public:
	Unit() : _x(0), _y(0) { }
	void moveTo(int x, int y)
	{
		_x = x;
		_y = y;
		std::cout << "unit moveTo: " << "_x: " << _x << ",_y: " << _y << std::endl;
	}
	int _x;
	int _y;
};

#endif // !UNIT_H

