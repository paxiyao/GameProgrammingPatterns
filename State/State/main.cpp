// 状态模式: 允许对象在其内部状态更改时更改其行为
// 1.如果只有一个角色可以采用使用静态状态对象,避免频繁释放和开辟内存,从而减少内存碎片
// 2.将状态封装成类,可以将不同的状态(角色动作状态、武器状态、翅膀状态等)完全解耦
// 3.角色类中增加enter和exit方法来实现角色进入或退出某种状态时更新UI,将UI和状态解耦,结构更清晰
// 4.层次状态机:有些输入操作可以只实现一次，在所有状态下复用
// 5.可使用下推自动机，可以把新的状态放到栈里面，当前状态永远存在栈顶，可以弹出栈顶的状态，改状态将被抛弃，与此同时上一个状态变成新的栈顶状态

#include "standState.h"

int main()
{
	Heroine* heroine = new Heroine(new StandState());
	heroine->handleInput(PRESS_DOWN);
	heroine->handleInput(PRESS_UP);

	delete heroine;

	system("pause");

	return 0;
}