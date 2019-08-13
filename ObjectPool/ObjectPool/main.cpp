/************************************************************************/
/* �����ģʽ��
	����ά�������ö��󼯺ϵĳ��ࡣÿ������֧��һ����in use����ѯ�����ж�����ǰ�Ƿ񡰻����
	��ʼ����ʱ������Ԥ�ȴ����������������(ͨ���ڵ�������������)���������ǳ�ʼ��Ϊ��not in use��״̬��
	������Ҫһ���¶���ʱ���������һ�������ҵ�һ�����õĶ��󣬳�ʼ��Ϊ��in use����Ȼ�󷵻�����
	��������Ҫ�ö���ʱ����������Ϊ��not in use��״̬������������Ϳ������ɴ��������٣�������Ҫ�����ڴ��������Դ��
*/
/************************************************************************/

/************************************************************************/
/* ʹ���龳��
	����ģʽ����Ϸ�й㷺ʹ�ã�������Ϸʵ����Ӿ�Ч�������ԵĶ�������Ҳ���ڲ�̫�ɼ������ݽṹ���統ǰ���ڲ��ŵ�������ʹ�ö����ʱ:
	����Ҫ�������������ٶ���
	����Ĵ�С���ơ�
	�ڶ��Ϸ��������������߿��ܵ����ڴ���Ƭ��
	ÿ�������װ���������ݿ����������֮�����Դ����Щ��Դ�Ļ�ȡ�ɱ��ܸߣ����ҿ������á�                                                                     */
/************************************************************************/

//���ڴ��д��һ����ͬ���͵Ķ�������������Ϸ������Щ����ʱ����CPU�����������ݾֲ���ģʽ��������

/************************************************************************/
/*��ȫ����
	������Ƭ���ͷ�����ܱȽ�������Ϸ�ǳ�ע���ʱ�Լ���ι����ڴ档һ���򵥵Ľ������ͨ������õġ�������Ϸ��ʼʱ��ȡһ����ڴ棬ֱ����Ϸ����ʱ���ͷ�����
	�������������Ҫ����Ϸ����ʱ���������ٶ�����ϵͳ��˵��һ��ʹ�ࡣ
	�����Ϊ�����ṩ��������������õĶ����������ڴ������������ֻ��Ԥ�ȷ�����һ����ڴ棬����������Ϸ����ʱ�ͷ�����
	���ڳص��û������ǿ������ɵط�����ͷŶ������ǵĺ������ݡ�                                                                  
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