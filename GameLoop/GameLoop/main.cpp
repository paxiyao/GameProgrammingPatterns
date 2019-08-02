//��Ϸѭ��ģʽ��ʵ���û�����ʹ������ٶ�����Ϸ�н�ʱ���ϵĽ���

#include <windows.h>

#define MS_PER_FRAME 0.16

void processInput()
{
	// �û�����
}

void update()
{
	// AI���������
}

void update(double time)
{
	// AI���������
}

void render()
{
	// ��Ⱦ
}

void render(double ratio)
{
	// ��Ⱦ
}

double getCurrentTime()
{
	// ��ȡ��ǰʱ��
	return 1.2;
}

int main()
{
	//1.��ͬ���Ĺ̶�ʱ�䲽��
	//	ֻ��Ҫ�����ܿ��ִ����Ϸѭ��
	//	�ص㣺�򵥣���Ϸ�ٶ�ֱ����Ӳ������Ϸ���Ӷȵ�Ӱ�졣�����κα仯��ֱ��Ӱ����Ϸ�ٶ�
	while (true)
	{
		processInput();
		update();
		render();
	}

	//2.ͬ���Ĺ̶�ʱ��
	//	����Ϸѭ��ĩβ����һ����ʱ������ͬ����ʽ����ֹ��Ϸ���еù���
	//	�ص㣺��Ϸ���ܻ��ܵú���������һ֡�ĸ��º���Ⱦ��ȥ�����ʱ�䣬��Ϸ���������
	//		������һģʽ��������������Ⱦ���룬�����û�н�һ���Ż��������������������¶��һȱ�ݡ�����������֡��Ⱦ��ͬ��ʱ����Ϸ�����
	while (true)
	{
		double start = getCurrentTime();
		processInput();
		update();
		render();
		Sleep(start + MS_PER_FRAME - getCurrentTime());
	}

	//3.��ʱ����
	//	������Ӧ����������Ӳ��ƽ̨��������Ϸ�޷�������ʵ��ʱ�䣬��������Խ��Խ���ʱ�䲽������
	//	��ʹ����Ϸ��ò�ȷ���Ҳ��ȶ������������ģ���ڱ�ʱ�����±����Ϊ����
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

	//4.��ʱ���µ�������ʱ��Ⱦ
	//	������Ӧ����������Ӳ��ƽ̨����Ϊ��Ϸ�ܹ�ʵʱ���£�������Ϸ�����������ʵʱ��
	//	�������ӣ�������Ҫȱ������ʵ�ʵ�ʵ��Ҫ�и���Ĺ���Ҫ��������ҪЭ������ʱ��Ĳ���ʹ���ڸ߶˻��㹻С��ͬ���ڵͶ˻��ϲ�������Ϸ�ܵ�̫��
	double lastTime = getCurrentTime();
	double lag = 0.0;
	while (true)
	{
		double current = getCurrentTime();
		double elapsed = current - lastTime;
		lastTime = current;
		lag += elapsed;
		processInput();

		// MS_PER_FRAME > update()�ĺ�������ʱ�䣬������Ϸ��Զ��������ʵ��ʱ�䣬�������ν֡ͬ���ĺ���
		while (lag >= MS_PER_FRAME)
		{
			update();
			lag -= MS_PER_FRAME;
		}
		render(lag / MS_PER_FRAME);
	}

	return;
}
