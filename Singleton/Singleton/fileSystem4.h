/// 进程运行前(main函数执行前)初始化
/// 优点:  1.不需要动态分配内存,提前创建和加载,使游戏运行流畅不会掉帧
///		  2.游戏通常需要严格控制内存在堆中的布局，以避免内存碎片

#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <assert.h>

//class FileSystem
//{
//public:
//	static FileSystem& instance()
//	{
//		return _instance;
//	}
//
//private:
//	FileSystem() { }
//	static FileSystem _instance;
//};
//
//FileSystem FileSystem::_instance = *(new FileSystem());

/// 使用静态类(所有类的成员和方法都是静态的)来实现运行前初始化的单例模式
//class FileSystem
//{
//public:
//	static char* readFile(char* path);
//	static void writeFile(char* path, char* contents);
//};

/// 限制单例只在某个区域访问或者私有
class FileSystem
{
public:
	FileSystem ()
	{
		assert(!_instantiated);	
		_instantiated = true;
	}

	~FileSystem()
	{
		_instantiated = false;
	}
private:
	static bool _instantiated;
};

bool FileSystem::_instantiated = false;

#endif // !FILESYSTEM_H
