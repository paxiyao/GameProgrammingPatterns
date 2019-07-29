// 延迟初始化,在第一次使用的时候进行初始化
// 优点: 1.在第一次使用的时候进行初始化,不提前占用内存

#ifndef FILESYSTEM_H
#define FILESYSTEM_H

class FileSystem
{
public:
	static FileSystem& instance()
	{
		if (_instance == nullptr)
			_instance = new FileSystem();
		
		return *_instance;
	}

private:
	FileSystem() { }
	static FileSystem* _instance;	
};

#endif // !FILESYSTEM_H
