// ˫����ģʽ:��̨�������͵�ǰ����������ǰ������ֻ���ڶ�ȡ���ݣ���̨������ֻ����д������
// ����ĺ���������:��״̬ͬʱ�����޸ĺͷ��ʵĳ�ͻ
// 1.״ֱ̬�ӱ���һ���̻߳��жϵĴ�����ֱ�ӷ���------------frameBuffer
// 2.����״̬�޸ĵĴ�����ʵ����������޸ĵ��Ǹ�״̬------------actor

#include <string>

#include "stage.h"
#include "comedian.h"

int main()
{
	Stage stage;

	Comedian* harry = new Comedian();
	harry->setName("harry");

	Comedian* baldy = new Comedian();
	baldy->setName("baldy");

	Comedian* chump = new Comedian();
	chump->setName("chump");

	harry->face(baldy);
	baldy->face(chump);
	chump->face(harry);

	stage.addActor(harry, 0);
	stage.addActor(baldy, 1);
	stage.addActor(chump, 2);

	harry->slap();
	// ��һ֡
	stage.update();
	// �ڶ�֡
	stage.update();
	// ����֡
	stage.update();
	// ����֡
	stage.update();

	system("pause");
	return 0;
}