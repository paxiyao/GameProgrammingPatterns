// �۲���ģʽ:	�ڶ���䶨��һ��һ�Զ��������ϵ���Ա㵱ĳ����״̬�����ı�ʱ����������������ϵ�����ж������յ�֪ͨ���Զ����и���
// ��Ϊ�۲�ģʽ��ͬ���ģ����۲��߶������ֱ�ӵ��ù۲����ǣ�����ζ�ţ����еĹ۲����Ƕ������ǵ�֪ͨ���غ󱻹۲��߲��ܼ�������
// �����κ�һ���۲��߶����п����������۲��߶���
// ��ʽ�۲��߽���˱��۲��߶����д洢�۲��߶���̬�����ڴ������

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