// 双缓冲模式:后台缓冲区和当前缓冲区，当前缓冲区只用于读取数据，后台缓冲区只用于写入数据
// 解决的核心问题是:对状态同时进行修改和访问的冲突
// 1.状态直接被另一个线程或中断的代码所直接访问------------frameBuffer
// 2.进行状态修改的代码访问到了其正在修改的那个状态------------actor

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
	// 第一帧
	stage.update();
	// 第二帧
	stage.update();
	// 第三帧
	stage.update();
	// 第四帧
	stage.update();

	system("pause");
	return 0;
}