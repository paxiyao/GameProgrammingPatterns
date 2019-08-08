// 类型对象模式:定义一个类型对象类和一个类型化对象类。每个类型对象实例表示不同的逻辑类型。每个类型化对象存储对描述其类型的类型对象的引用。

// 使用时机:
// 这种模式在任何需要定义各种不同“种类”的东西的时候都是有用的，但是将这些种类放入语言的类型系统中太死板了。特别是，当这两个选项都为真时，它就非常有用:
// 你不知道你需要什么类型的预先。(例如，如果我们的游戏需要支持下载包含新怪物的内容呢 ? )
// 您希望能够修改或添加新类型，而不需要重新编译或更改代码。

// 使类型对象更像类型:构造函数
// 用我们现在所拥有的，我们直接建造一个怪物，并负责传递它的品种。
// 这与在大多数OOP语言中实例化常规对象的方式有点相反——我们通常不会分配一块空白内存，然后给它类。
// 相反，我们在类本身上调用构造函数，它负责给我们一个新的实例。

// 那么，为什么要这样做呢 ? 创建对象有两个步骤 : 分配和初始化。Monster的构造函数允许我们执行所有需要的初始化。在我们的例子中，这只是存储品种，但一个完整的游戏将加载图形，初始化怪物的AI，并做其他设置工作。
// 然而，这一切都发生在分配之后。在调用怪物的构造函数之前，我们已经有了一块内存可以将怪物放入其中。在游戏中，我们通常也想控制对象创建的这一方面 : 我们通常会使用自定义分配器或对象池模式来控制对象在内存中的最终位置。
//在Breed中定义一个“构造函数”给我们提供了一个放置逻辑的位置。newMonster()函数可以在将控制权传递给Monster进行初始化之前从池或自定义堆中提取内存，而不是简单地调用new。通过将此逻辑放入Breed中，在惟一有能力创建怪物的函数中，我们确保所有怪物都经过我们想要的内存管理方案。

// 直接在json文件中读取怪物数据
//{
//"Troll": {
//	"health": 25,
//		"attack" : "The troll hits you!"
//},
//"Troll Archer" : {
//		"parent": "Troll",
//			"health" : 0,
//			"attack" : "The troll archer fires an arrow!"
//	},
//		"Troll Wizard" : {
//			"parent": "Troll",
//				"health" : 0,
//				"attack" : "The troll wizard casts a spell on you!"
//		}
//}

#include "breed.h"

int main()
{
	Breed someBread(NULL, 200, "The troll hits you!");
	Monster* monster = someBread.newMonster();

	return 0;
}

