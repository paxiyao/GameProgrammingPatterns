// ��Ϸ����ģʽ:��Ϸ����ά��һ�����󼯺ϡ�ÿ������ʵ��һ��update()��������ģ����ÿһ֡����Ϊ��ÿһ֡��Ϸ���¶��󼯺��е�ÿ������
// ʹ��ʱ����1.��Ϸ���д��������ʵ����Ҫͬ��
//			 2.ÿ���������Ϊ��������������
//		     3.����ʱ�����ƶ���һֱ��Ҫ��ģ��

// ��Ϸʵ��ʹ�����ģʽ��ʹ������update()����ʵ�������ϣ���������ʵ�屾���ϡ�
// ��ʹ�����Ա��ⴴ�����ӵ�ʵ�����νṹ�������������Ϊ���෴����ֻ���Ϻ�ƥ�����


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