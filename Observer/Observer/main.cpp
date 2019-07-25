// 观察者模式:	在对象间定义一种一对多的依赖关系，以便当某对象状态发生改变时，与它存在依赖关系的所有对象都能收到通知并自动进行更新
// 因为观察模式是同步的，被观察者对象可以直接调用观察者们，这意味着，所有的观察者们都从他们的通知返回后被观察者才能继续工作
// 其中任何一个观察者对象都有可能阻塞被观察者对象
// 链式观察者解决了被观察者对象中存储观察者对象动态分配内存的问题

#include "physics.h"
#include "entity.h"
#include "achievements.h"
#include "audio.h"

int main()
{
	Physics* phy = new Physics();
	Observer* achie = new Achievements();
	phy->addObserver(achie);
	Observer* audio = new Audio();
	phy->addObserver(audio);

	phy->onNotify(ACHIEVEMENT_FELL_OFF_BRIDGE);

	return 0;
}