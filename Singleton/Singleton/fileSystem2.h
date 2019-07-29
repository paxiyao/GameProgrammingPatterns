// 优点: 1.在需要的时候再进行初始化,不会提前占用内存
// c++11新标准: 局部静态成员只会初始化一次(即使是并发的),所以这种初始化方式是线程安全的
// 注意: 这里说的是单例的初始化线程安全,而不是整个单例类线程安全

#ifndef FILESYSTEM_H
#define FILESYSTEM_H

class FileSystem
{
public:
	static FileSystem& instance()
	{
		static FileSystem* _instance = new FileSystem();

		return *_instance;
	}
private:
	FileSystem() { }
};

#endif // !FILESYSTEM_H
