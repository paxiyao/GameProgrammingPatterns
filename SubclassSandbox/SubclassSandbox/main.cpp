// ����ɳ��:���ඨ��һ������ɳ�䷽���ͼ����ṩ�Ĳ����������Ǳ��Ϊprotected��������ر��������ǹ�������ʹ�õġ�ÿ��������ɳ�����඼ʹ���ṩ�Ĳ���ʵ��ɳ�䷽����
// ʹ��ʱ��:
//         ����һ�����࣬���а�����������ࡣ
//         �����ܹ��ṩ�����������Ҫִ�е����в�����
//         �����д�����Ϊ�ص�����ϣ��ʹ����֮������׹�����롣
//         ��ϣ����С����Щ��������������ಿ��֮�����ϡ�

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