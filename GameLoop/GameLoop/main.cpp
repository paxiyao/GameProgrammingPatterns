//游戏循环模式：实现用户输入和处理器速度在游戏行进时间上的解耦

#include <windows.h>

#define MS_PER_FRAME 0.16

void processInput()
{
	// 用户输入
}

void update()
{
	// AI和物理计算
}

void update(double time)
{
	// AI和物理计算
}

void render()
{
	// 渲染
}

void render(double ratio)
{
	// 渲染
}

double getCurrentTime()
{
	// 获取当前时间
	return 1.2;
}

int main()
{
	//1.非同步的固定时间步长
	//	只需要尽可能快地执行游戏循环
	//	特点：简单，游戏速度直接受硬件和游戏复杂度的影响。出现任何变化，直接影响游戏速度
	while (true)
	{
		processInput();
		update();
		render();
	}

	//2.同步的固定时长
	//	在游戏循环末尾增加一个延时或者是同步方式来防止游戏运行得过快
	//	特点：游戏可能会跑得很慢。假如一帧的更新和渲染花去过多的时间，游戏将会变慢。
	//		由于这一模式并不将更新与渲染分离，因此在没有进一步优化的情况下它将很容易显露这一缺陷。不进行外置帧渲染并同步时，游戏会变慢
	while (true)
	{
		double start = getCurrentTime();
		processInput();
		update();
		render();
		Sleep(start + MS_PER_FRAME - getCurrentTime());
	}

	//3.变时步长
	//	它能适应过快或过慢的硬件平台。假如游戏无法跟上真实的时间，则它将以越来越大的时间步长跟上
	//	它使得游戏变得不确定且不稳定。物理和网络模块在变时步长下变得尤为困难
	double lastTime = getCurrentTime();
	while (true)
	{
		double current = getCurrentTime();
		double elapsed = current - lastTime;
		processInput();
		update(elapsed);
		render();
		lastTime = current;
	}

	//4.定时更新迭代，变时渲染
	//	它能适应过快或过慢的硬件平台。因为游戏能够实时更新，所以游戏不会落后于真实时间
	//	它更复杂，它的主要缺陷在于实际的实现要有更多的工作要做。你需要协调更新时间的步长使其在高端机足够小，同事在低端机上不会让游戏跑得太慢
	double lastTime = getCurrentTime();
	double lag = 0.0;
	while (true)
	{
		double current = getCurrentTime();
		double elapsed = current - lastTime;
		lastTime = current;
		lag += elapsed;
		processInput();

		// MS_PER_FRAME > update()的函数处理时间，否则游戏永远跟不上现实的时间，这就是所谓帧同步的核心
		while (lag >= MS_PER_FRAME)
		{
			update();
			lag -= MS_PER_FRAME;
		}
		render(lag / MS_PER_FRAME);
	}

	return;
}
