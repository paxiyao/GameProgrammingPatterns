// 命令模式就是一个对象化的方法调用
// 例如: 跳(jump), 走(move)是两个不同的行为
// 面向过程: 两个函数不同的函数接口对应两种行为
// 面向对象: 将跳和走两个动作进行对象化，封装成类，都继承Command,放到Command的excute方法去执行具体的动作
// 命令模式一般用在游戏的按钮，鼠标，键盘等交互

#include<vector>

#include "jumpCommand.h"
#include "moveCommand.h"

const int count = 5;

int main()
{
	std::vector<Command*> cVector;
	int curCommandIdx = 0;	// 当前命令下标

	// 角色
	Unit* unit = new Unit();

	for (unsigned int i = 0; i < count; i++)
	{
		cVector.push_back(new JumpCommand(unit, i, i));
		cVector[i]->execute();
		curCommandIdx = i;
	}

	// 重做4步
	curCommandIdx = curCommandIdx - 4;
	if (curCommandIdx < 0) // 如果不够4个命令从第一个开始
		curCommandIdx = 0;
	while (curCommandIdx < count)
		cVector[curCommandIdx++]->execute();

	// 撤销1步
	cVector[cVector.size() - 1]->undo();
	cVector.pop_back();

	system("pause");

	return 0;
}
