// 游戏更新模式:游戏世界维持一个对象集合。每个对象实现一个update()方法，来模拟他每一帧的行为。每一帧游戏更新对象集合中的每个对象
// 使用时机：1.游戏中有大量对象和实体需要同步
//			 2.每个对象的行为独立于其他对象
//		     3.随着时间推移对象一直需要被模拟

// 游戏实体使用组件模式。使用它，update()将在实体的组件上，而不是在实体本身上。
// 这使您可以避免创建复杂的实体类层次结构来定义和重用行为。相反，您只需混合和匹配组件


#include "entity.h"

#define MAX_ENTITIES 100

class Skeleton : public Entity
{
public:
	Skeleton()
		: patrollingLeft_(false)
	{}

	virtual void update()
	{
		if (patrollingLeft_)
		{
			setX(x() - 1);
			if (x() == 0) patrollingLeft_ = false;
		}
		else
		{
			setX(x() + 1);
			if (x() == 100) patrollingLeft_ = true;
		}
	}

private:
	bool patrollingLeft_;
};

class Statue : public Entity
{
public:
	Statue(int delay)
		: frames_(0),
		delay_(delay)
	{}

	virtual void update()
	{
		if (++frames_ == delay_)
		{
			shootLightning();

			// Reset the timer.
			frames_ = 0;
		}
	}

private:
	int frames_;
	int delay_;

	void shootLightning()
	{
		// Shoot the lightning...
	}
};

class World
{
public:
	World()
		:_numEntities(0)
	{}

	void gameLoop()
	{
		while (true)
		{
			// Handle user input...

			// Update each entity.
			for (unsigned int i = 0; i < _numEntities; i++)
			{
				_entities[i]->update();
			}

			// Physics and rendering...
		}
	}

private:
	Entity* _entities[MAX_ENTITIES];
	int _numEntities;
};