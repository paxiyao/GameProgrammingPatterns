// 子类沙盒:基类定义一个抽象沙箱方法和几个提供的操作。将它们标记为protected可以清楚地表明它们是供派生类使用的。每个派生的沙箱子类都使用提供的操作实现沙箱方法。
// 使用时机:
//         您有一个基类，其中包含许多派生类。
//         基类能够提供派生类可能需要执行的所有操作。
//         子类中存在行为重叠，您希望使它们之间更容易共享代码。
//         您希望最小化这些派生类与程序其余部分之间的耦合。

#include <iostream>

#include "skyLaunch.h"

int main()
{
	Audio* audio = new Audio();
	Particle* particle = new Particle();
	SuperPower::init(audio, particle);

	SkyLaunch* skyLaunch = new SkyLaunch();
	skyLaunch->activate();

	std::cout << sizeof(*skyLaunch) << std::endl;

	delete audio;
	delete particle;
	delete skyLaunch;

	return 0;
}