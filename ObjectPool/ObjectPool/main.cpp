/************************************************************************/
/* 对象池模式：
	定义维护可重用对象集合的池类。每个对象都支持一个“in use”查询，以判断它当前是否“活动”。
	初始化池时，它会预先创建对象的整个集合(通常在单个连续分配中)，并将它们初始化为“not in use”状态。
	当您想要一个新对象时，向池请求一个。它找到一个可用的对象，初始化为“in use”，然后返回它。
	当不再需要该对象时，将其设置为“not in use”状态。这样，对象就可以自由创建和销毁，而不需要分配内存或其他资源。
*/
/************************************************************************/

/************************************************************************/
/* 使用情境：
	这种模式在游戏中广泛使用，用于游戏实体和视觉效果等明显的东西，但也用于不太可见的数据结构，如当前正在播放的声音。使用对象池时:
	您需要经常创建和销毁对象。
	物体的大小相似。
	在堆上分配对象很慢，或者可能导致内存碎片。
	每个对象封装了诸如数据库或网络连接之类的资源，这些资源的获取成本很高，并且可以重用。                                                                     */
/************************************************************************/

//在内存中打包一堆相同类型的对象有助于在游戏遍历这些对象时保持CPU缓存满。数据局部性模式就是这样

/************************************************************************/
/*两全其美
	由于碎片化和分配可能比较慢，游戏非常注意何时以及如何管理内存。一个简单的解决方案通常是最好的——在游戏开始时获取一大块内存，直到游戏结束时才释放它。
	但这对于我们需要在游戏运行时创建和销毁东西的系统来说是一种痛苦。
	对象池为我们提供了两个世界中最好的东西。对于内存管理器，我们只是预先分配了一大块内存，而不是在游戏进行时释放它。
	对于池的用户，我们可以自由地分配和释放对象到我们的核心内容。                                                                  
	*/
/************************************************************************/

#include <assert.h>

class Particle
{
public:
	Particle()
		: framesLeft_(0)
	{}

	Particle* getNext() const { return state_.next; }
	void setNext(Particle* next) { state_.next = next; }

	void init(double x, double y,
		double xVel, double yVel, int lifetime)
	{
		state_.live.x = x; state_.live.y = y;
		state_.live.xVel = xVel; state_.live.yVel = yVel;
		framesLeft_ = lifetime;
	}

	bool inUse() const { return framesLeft_ > 0; }

	bool animate()
	{
		if (!inUse()) return false;

		framesLeft_--;
		state_.live.x += state_.live.xVel;
		state_.live.y += state_.live.yVel;

		return framesLeft_ == 0;
	}

private:
	int framesLeft_;
	union
	{
		// State when it's in use.
		struct
		{
			double x, y;
			double xVel, yVel;
		} live;

		// State when it's available.
		Particle* next;
	} state_;
};

class ParticlePool
{
public:
	ParticlePool()
	{
		// The first one is available.
		firstAvailable_ = &particles_[0];

		// Each particle points to the next.
		for (int i = 0; i < POOL_SIZE - 1; i++)
		{
			particles_[i].setNext(&particles_[i + 1]);
		}

		// The last one terminates the list.
		particles_[POOL_SIZE - 1].setNext(NULL);
	}

	void create(double x, double y,
		double xVel, double yVel,
		int lifetime)
	{
		// Make sure the pool isn't full.
		assert(firstAvailable_ != NULL);

		// Remove it from the available list.
		Particle* newParticle = firstAvailable_;
		firstAvailable_ = newParticle->getNext();

		newParticle->init(x, y, xVel, yVel, lifetime);
	}

	void animate()
	{
		for (int i = 0; i < POOL_SIZE; i++)
		{
			if (particles_[i].animate())
			{
				// Add this particle to the front of the list.
				particles_[i].setNext(firstAvailable_);
				firstAvailable_ = &particles_[i];
			}
		}
	}
	// ...
private:
	static const int POOL_SIZE = 100;
	Particle particles_[POOL_SIZE];
	Particle* firstAvailable_;
};

int main()
{
	ParticlePool* particlePool = new ParticlePool();
	particlePool->create(1, 1, 1, 1, 5);

	delete particlePool;

	return 0;
}