#ifndef ENTITY_H
#define ENTITY_H

class Entity
{
public:
	Entity()
		:_x(0), _y(0)
	{}
	virtual ~Entity() {}
	virtual void update() = 0;

	double x() const { return _x; }
	double y() const { return _y; }

	void setX(double x) { _x = x; }
	void setY(double y) { _y = y; }

private:
	double _x;
	double _y;
};

#endif // !ENTITY_H
